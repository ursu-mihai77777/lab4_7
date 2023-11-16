#include <iostream>
#include <vector>


class Address;


class Address {
private:
    std::string street;
    std::string city;
    std::string country;

public:
    Address(const std::string& street, const std::string& city, const std::string& country)
        : street(street), city(city), country(country) {}

    // Getter methods
    const std::string& getStreet() const {
        return street;
    }

    const std::string& getCity() const {
        return city;
    }

    const std::string& getCountry() const {
        return country;
    }

    
    void display() const {
        std::cout << street << ", " << city << ", " << country << std::endl;
    }
};


class Driver {
private:
    std::string name;
    int driverLicenseNumber;

public:
    Driver(const std::string& name, int driverLicenseNumber)
        : name(name), driverLicenseNumber(driverLicenseNumber) {}

    // Getter methods
    const std::string& getName() const {
        return name;
    }

    int getDriverLicenseNumber() const {
        return driverLicenseNumber;
    }

    
    void display() const {
        std::cout << "Driver: " << name << ", License Number: " << driverLicenseNumber << std::endl;
    }
};


class Engine {
protected:
    std::string type;

public:
    Engine(const std::string& type) : type(type) {}

    // Getter method
    const std::string& getType() const {
        return type;
    }
};


class Car : public Engine {
private:
    std::string make;
    std::string model;

public:
    Car(const std::string& type, const std::string& make, const std::string& model)
        : Engine(type), make(make), model(model) {}

    // Display car information
    void display() const {
        std::cout << "Car: " << make << " " << model << ", Engine Type: " << type << std::endl;
    }
};


class Commuter {
private:
    std::string name;
    int commuterID;

public:
    Commuter(const std::string& name, int commuterID)
        : name(name), commuterID(commuterID) {}

    
    void display() const {
        std::cout << "Commuter: " << name << ", ID: " << commuterID << std::endl;
    }
};


class Bus : public Engine {
private:
    std::string busNumber;
    Driver driver;
    std::vector<Commuter> commuters;

public:
    Bus(const std::string& type, const std::string& busNumber, const Driver& driver)
        : Engine(type), busNumber(busNumber), driver(driver) {}

    
    void addCommuter(const Commuter& commuter) {
        commuters.push_back(commuter);
    }

    
    void display() const {
        std::cout << "Bus Number: " << busNumber << ", Engine Type: " << type << std::endl;
        driver.display();
        std::cout << "Commuters on the bus:\n";
        for (const auto& commuter : commuters) {
            commuter.display();
        }
    }
};


class Mosquito {
private:
    std::string name; // Just for fun!
public:
    Mosquito(const std::string& name) : name(name) {}

    // Display mosquito information
    void display() const {
        std::cout << "Mosquito: " << name << std::endl;
    }
};


class BusStation {
private:
    Address address;
    std::vector<Bus> buses;

public:
    BusStation(const Address& address) : address(address) {}

    
    void addBus(const Bus& bus) {
        buses.push_back(bus);
    }

    
    void display() const {
        std::cout << "Bus Station Address:\n";
        address.display();
        std::cout << "Buses at the station:\n";
        for (const auto& bus : buses) {
            bus.display();
        }
    }
};

int main() {
    
    Address busStationAddress("Calea Bucuresti", "Craiova", "Romania");
    BusStation busStation(busStationAddress);

    Driver busDriver("Marius", 987654);
    Bus bus("Diesel", "E1T", busDriver);

    Commuter commuter1("Alin", 1);
    Commuter commuter2("Bogdan", 2);

    bus.addCommuter(commuter1);
    bus.addCommuter(commuter2);

    Car car("Gasoline", "Toyota", "Camry");

    
    busStation.addBus(bus);

    Mosquito mosquito("Aedes aegypti");

    
    std::cout << "Bus Station Information:\n";
    busStation.display();

    std::cout << "\nCar Information:\n";
    car.display();

    std::cout << "\nMosquito Information:\n";
    mosquito.display();

    return 0;
}
