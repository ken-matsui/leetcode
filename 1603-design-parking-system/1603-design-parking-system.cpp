class ParkingSystem {
public:
    int big, medium, small;

    ParkingSystem(int _big, int _medium, int _small)
        : big{_big}, medium{_medium}, small{_small} {
    }

    bool addCar(int carType) {
        if (carType == 1 && big > 0) {
            --big;
            return true;
        } else if (carType == 2 && medium > 0) {
            --medium;
            return true;
        } else if (carType == 3 && small > 0) {
            --small;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
