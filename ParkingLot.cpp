#include<iostream>
#include<chrono>
#include<vector>

using namespace std;

class Vehicle
{
private:
    int vrow;
    int vspot;
    string type;
    chrono::time_point<chrono::system_clock> parkingStartTime;
public:
    Vehicle(string s)
    {
        vrow = -1;
        vspot = -1;
        type = s;
    }

    void occupyspace(int r, int c)
    {
        vrow = r;
        vspot = c;
        parkingStartTime = chrono::system_clock::now();
    }

    void vacatespot()
    {
        vrow = -1;
        vspot = -1;
    }

    int calculateParkingDurationInHours()
    {
        auto now = chrono::system_clock::now();
        auto duration = chrono::duration_cast<chrono::hours>(now - parkingStartTime);
        cout<<"Debug time: "<<duration.count()<<endl;
        return duration.count();
    }

    string getname()
    {
        return type;
    }
    virtual int calculateParkingFee() = 0;
    virtual string getType() = 0;
};

class Car: public Vehicle
{
public:
    
    Car(string s): Vehicle(s)
    {
        
    }
    string getType()
    {
        return "car";
    }

    int calculateParkingFee()
    {
        return 5* calculateParkingDurationInHours();
    }
};

class Bike: public Vehicle
{
public: 
    Bike(string s): Vehicle(s)
    {

    }
    string getType()
    {
        return "Bike";
    }

    int calculateParkingFee()
    {
        return 2* calculateParkingDurationInHours();
    }
};

class Parking
{
private:    
    int row;
    int spotsPerRow;
    vector<vector<Vehicle*>> grid;

public:
    void create(int r, int c)
    {
        row = r;
        spotsPerRow = c;
        grid.resize(r);
        for(int i = 0;  i < r; i++)
        {
            grid[i].resize(c);
        }
    }

    pair<int,int> findvacantSpot()
    {
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<spotsPerRow; j++)
            {
                if(grid[i][j] == nullptr)
                {
                    return {i,j};
                }
            }
        }
        cout<<"No valid parking space found!"<<endl;
        return {-1,-1};
    }

    bool park(Vehicle* v, int rowNum, int spotNum)
    {
        if(grid[rowNum][spotNum] != nullptr)
        {
            cout<<"so sorry! no parking available at "<<rowNum<<", "<<spotNum<<endl;
            return false;
        }
        v->occupyspace(rowNum,spotNum);
        grid[rowNum][spotNum] = v;
        cout<<"Thanks for parking! your vehicle is at "<<rowNum<<", "<<spotNum<<endl;
        return true;
    }

    bool park(Vehicle* v)
    {
        pair<int,int> spot = findvacantSpot();
        if(spot.first >= 0 and spot.second >= 0 && spot.first < row && spot.second < spotsPerRow)
        {
            return park(v, spot.first, spot.second);
        }
        cout<<"Sorry no parking availble!!!"<<endl;
        return false;
    }

    void leave(Vehicle* v)
    {
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<spotsPerRow; j++)
            {
                if(grid[i][j] == v)
                {
                    grid[i][j] = nullptr;
                    int fee = v->calculateParkingFee();
                    cout<<" Fee is - rs. "<<fee<<endl;
                    v->vacatespot();
                }
            }
        }
    }

    void printParking()
    {
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<spotsPerRow; j++)
            {
                if(grid[i][j] != nullptr) 
                {
                    cout<<grid[i][j]->getname()<<" ";
                }
                else 
                {   
                    cout<<grid[i][j]<<" ";
                }
            }
            cout<<endl;
        }
    }

};

int main()
{   
    Parking p;
    p.create(3,2);
    p.printParking();

    Car c1("c1"), c2("c2");
    Bike b1("b1");

    p.park(&c1);
    p.printParking();

    p.park(&c2);
    p.printParking();

    p.leave(&c2);
    p.printParking();

}