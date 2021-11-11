#include <iostream>
#include <vector>
using namespace std;
enum class NameStation
{
    Waiting,
    Victory_Boulevard,
    One_May,
    Nearby_gardens,
    Distant_gardens,
    Alekseevskie_gardens,
    Car_market,
    House_OF_Sports,
    Railway_hospital,
    Morozova
};

string ReturnName(NameStation name)
{
    switch (name)
    {
    case NameStation::Victory_Boulevard:
        return "Бульвар победы";
    case NameStation::One_May:
        return "1 мая";
    case NameStation::Nearby_gardens:
        return "Ближние сады";
    case NameStation::Distant_gardens:
        return "Дальние сады";
    case NameStation::Alekseevskie_gardens:
        return "Алексеевские сады";
    case NameStation::Car_market:
        return "Авторынок";
    case NameStation::House_OF_Sports:
        return "Дом спорта";
    case NameStation::Railway_hospital:
        return "Ж/Д Госпиталь";
    case NameStation::Morozova:
        return "Морозова";
    }
}

class Passenger 
{
private:
    string name;
    NameStation desiredSation;
public:
    Passenger () :  name(), desiredSation(NameStation::Waiting){}
    const string GetNamePassenger() { return name; }
    const NameStation GetNameStationPassenger() { return desiredSation; }
    void SetNamePassenger(const string& NewName) { name = NewName; }
    void SetNameStation(const NameStation& NewName) { desiredSation = NewName; }
};

class Station : public Passenger
{
private:
    NameStation thisStation;
    vector<Passenger> passenger;
public:
    Station() : thisStation(NameStation::Waiting), passenger(NULL){}
    const NameStation GetNameStation() { return thisStation; }
    const vector<Passenger> GetPassenger() { return passenger; }
    void SetNameThisStation(const NameStation& NewName) { thisStation = NewName; }
    void AddPassengerInStation(const string& NamePasseger,const NameStation& nameStation)
    {
        Passenger tmp;
        tmp.SetNamePassenger(NamePasseger);
        tmp.SetNameStation(nameStation);
        passenger.push_back(tmp);
    }
    void RemovePassengerInStation(int idPassenger)
    {
        passenger.erase(passenger.begin() + idPassenger);
    }
};

void GenericPassengerInStation(vector<Station>& stations)
{
    for (int i = 0; i < 9; i++)
    {
        stations.push_back(Station());
    }
    stations[0].SetNameThisStation(NameStation::Victory_Boulevard);
    stations[0].AddPassengerInStation("Петрушин", NameStation::One_May);
    stations[0].AddPassengerInStation("Щукин", NameStation::One_May);
    stations[0].AddPassengerInStation("Хохлов", NameStation::Nearby_gardens);

    stations[1].SetNameThisStation(NameStation::One_May);
    stations[1].AddPassengerInStation("Понасенко", NameStation::Alekseevskie_gardens);

    stations[2].SetNameThisStation(NameStation::Nearby_gardens);

    stations[3].SetNameThisStation(NameStation::Distant_gardens);

    stations[4].SetNameThisStation(NameStation::Alekseevskie_gardens);

    stations[5].SetNameThisStation(NameStation::Car_market);
    stations[5].AddPassengerInStation("Хохлов", NameStation::Morozova);
    stations[5].AddPassengerInStation("Зочин", NameStation::Morozova);

    stations[6].SetNameThisStation(NameStation::House_OF_Sports);

    stations[7].SetNameThisStation(NameStation::Railway_hospital);

    stations[8].SetNameThisStation(NameStation::Morozova);
    stations[8].AddPassengerInStation("Дорова", NameStation::House_OF_Sports);
}

int GetNumberOfPassengers(vector<Station> stations, NameStation namestation)
{
    for (int i = 0; i < stations.size(); i++)
    {
        if (namestation == stations[i].GetNameStation())
        {
            return stations[i].GetPassenger().capacity();
        }
    }
    return 0;
}
class Taxi : public Station
{
private:
    string name;
    int places;
    NameStation nowStation;
    vector<NameStation> route;
    vector<Passenger> passenger;
public:
    Taxi(string nameTaxi,int p) : name(nameTaxi),places(p), nowStation(NameStation::Waiting),route(NULL),passenger(NULL){}
    void GenericRouteOne()
    {
        route.clear();
        route.push_back(NameStation::Victory_Boulevard);
        route.push_back(NameStation::One_May);
        route.push_back(NameStation::Nearby_gardens);
        route.push_back(NameStation::Distant_gardens);
        route.push_back(NameStation::Alekseevskie_gardens);
        nowStation = NameStation::Victory_Boulevard;
    }
    void GenericRouteTwo()
    {
        route.clear();
        route.push_back(NameStation::Car_market);
        route.push_back(NameStation::House_OF_Sports);
        route.push_back(NameStation::Railway_hospital);
        route.push_back(NameStation::Morozova);
        nowStation = NameStation::Car_market;
    }
    void PassengerInTaxi(vector<Station>& stations)
    {
        int numStation = static_cast<int>(nowStation)-1;
        vector<Passenger> stationsPassenger = stations[numStation].GetPassenger();
        for (int i = 0; i < stationsPassenger.size(); i++)
        {
            if (passenger.size() < places)
            {
                if (IsStationsHave(stationsPassenger[i].GetNameStationPassenger()))
                {
                    passenger.push_back(stationsPassenger[i]);
                    stations[numStation].RemovePassengerInStation(i);
                }
            }
        }
    }
    void PassengerInStation()
    {
        if (passenger.size() == 0)
        {
            return;
        }
        for (int i = 0; i < passenger.size(); i++)
        {
            if (nowStation == passenger[i].GetNameStationPassenger())
                passenger.erase(passenger.begin() + i);
        }
    }
    void OutputTaxiRoute(vector<Station> stations)
    {
        cout << "Остановка (Пассажиры) : Такси(места | пассажиры)" << endl;
        for (int i = 0; i < route.size(); i++)
        {
            cout << ReturnName(route[i]) << " (" << GetNumberOfPassengers(stations, route[i]) << ") :";
            if (route[i] == nowStation)
            {
                cout << name << " (" << places << " | " << passenger.size() << ")";
            }
            cout << endl;
        }
    }
private:
    bool IsStationsHave(NameStation nameStation)
    {
        for (int i = 0; i < route.size(); i++)
        {
            if (route[i] == nameStation)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    setlocale(LC_ALL, "Rus");
    vector<Station> stations;
    GenericPassengerInStation(stations);
    Taxi t1("Игорь",2);
    t1.GenericRouteOne();
    t1.PassengerInTaxi(stations);
    t1.OutputTaxiRoute(stations);
    return 0;
}


