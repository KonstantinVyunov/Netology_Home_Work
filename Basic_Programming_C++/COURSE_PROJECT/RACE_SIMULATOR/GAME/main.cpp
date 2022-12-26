#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Vehicle {
private:
	string name{};
	double speed = NULL;
protected:
	Vehicle(string name, double speed) {
		this->name = name;
		this->speed = speed;
	}
public:
	Vehicle() : Vehicle("Vehicle", NULL) {}

	string getName() const {
		return this->name;
	}
	double getSpeed() const {
		return this->speed;
	}

	virtual ~Vehicle() = default;
};

class GroundVehicle : public Vehicle {
private:
	double moving_time = NULL;
protected:
	GroundVehicle(string name, double speed, double moving_time) : Vehicle(name, speed) {
		this->moving_time = moving_time;
	}
public:
	GroundVehicle() : GroundVehicle("GroundVehicle", 0, 0) {}

	double movingTime() const {
		return this->moving_time;
	}

	virtual ~GroundVehicle() = default;
};

class Camel : public GroundVehicle {
private:
	const double first_resting_time = 5;
	const double other_resting_time = 8;
protected:
	Camel(string name, double speed, double moving_time) : GroundVehicle(name, speed, moving_time) {}
public:
	Camel() : Camel("Camel", 10, 30) {}

	double firstRestingTime() const {
		return this->first_resting_time;
	}
	double otherRestingTime() const {
		return this->other_resting_time;
	}

	virtual ~Camel() = default;
};

class Horse : public GroundVehicle { // —коростной ¬ерблюд
private:
	const double first_resting_time = 5;
	const double second_resting_time = 6.5;
	const double other_resting_time = 8;
protected:
	Horse(string name, double speed, double moving_time ) : GroundVehicle(name, speed, moving_time) {}
public:
	Horse() : Horse("Horse", 40, 10) {}

	double firstRestingTime() const {
		return this->first_resting_time;
	}
	double secondRestingTime() const {
		return this->second_resting_time;
	}
	double otherRestingTime() const {
		return this->other_resting_time;
	}

	virtual ~Horse() = default;
};

class Centaur : public GroundVehicle {
private:
	const double resting_time = 2;
protected:
	Centaur(string name, double speed, double moving_time) : GroundVehicle(name, speed, moving_time) {}
public:
	Centaur() : Centaur("Centaur", 15, 8) {}

	double restingTime() const {
		return this->resting_time;
	}

	virtual ~Centaur() = default;
};

class Boots : public GroundVehicle { // —апоги —короходы
private:
	const double first_resting_time = 10;
	const double other_resting_time = 5;
protected:
	Boots(string name, double speed, double moving_time) : GroundVehicle(name, speed, moving_time) {}
public:
	Boots() : Boots("Boots", 6, 60) {}

	double firstRestingTime() const {
		return this->first_resting_time;
	}
	double otherRestingTime() const {
		return this->other_resting_time;
	}

	virtual ~Boots() = default;
};

class AirVehicle : public Vehicle {
private:
	
protected:
	AirVehicle(string name, double speed) : Vehicle (name, speed) {}
public:
	AirVehicle() : AirVehicle("AirVehicle", 0) {};

	virtual ~AirVehicle() = default;
};

class Eagle : public AirVehicle {
private:
	double distance_reduction_factor = 0.6;
public:
	Eagle() : AirVehicle("Eagle", 8) {}

	double getReductionFactor() const {
		return this->distance_reduction_factor;
	}

	virtual ~Eagle() = default;
};

class FlyingCarpet : public AirVehicle {
private:
	double distance_reduction_factor_less_1000 = 1;
	double distance_reduction_factor_less_5000 = 0.03;
	double distance_reduction_factor_less_10000 = 0.1;
	double distance_reduction_factor_more_10000 = 0.05;
public:
	FlyingCarpet() : AirVehicle("FlyingCarpet", 10) {}

	double getReductionFactor1000() const {
		return this->distance_reduction_factor_less_1000;
	}

	double getReductionFactor5000() const {
		return this->distance_reduction_factor_less_5000;
	}

	double getReductionFactorLess10000() const {
		return this->distance_reduction_factor_less_10000;
	}

	double getReductionFactorMore10000() const {
		return this->distance_reduction_factor_more_10000;
	}

	virtual ~FlyingCarpet() = default;
};

class Broom : public AirVehicle { // ћетла
private:
	double distance_reduction_factor = 0.01;
public:
	Broom() : AirVehicle("Broom", 20) {}

	double getReductionFactor() const {
		return this->distance_reduction_factor;
	}

	virtual ~Broom() = default;
};

enum class Type { ground = 1, air = 2, mixed = 3 };

struct Race {
	Type type{};
	int distance = 0;
	vector<Vehicle> vehicles;
	bool readiness = false;
};

enum class GroundVehiclesList { Camel = 1, Horse, Centaur, Boots };
enum class AirVehiclesList { FlyingCarpet = 1, Eagle, Broom };
enum class MixedVehiclesList { Camel = 1, Horse, Centaur, Boots, FlyingCarpet, Eagle, Broom };

Type chooseRaceType(Race& race) {
	int choice = 0;

	do {
		cin >> choice;
		switch (static_cast<Type>(choice)) {
		case Type::ground:
			cout << "You have selected the Ground Race! Let's go further!" << endl;
			race.type = Type::ground;
			break;
		case Type::air:
			cout << "You have selected the Air Race! Let's go further!" << endl;
			race.type = Type::air;
			break;
		case Type::mixed:
			cout << "You have selected the Mixed Race! Let's go further!" << endl;
			race.type = Type::mixed;
			break;
		default:
			cout << "You have selected the wrong Race Type!" << endl;
			cout << "Try again: ";
			break;
		}
	} while (choice != (int)Type::ground && choice != (int)Type::air && choice != (int)Type::mixed);
	return race.type;
}

int enterRaceDistance(Race& race) {
	cin >> race.distance;
	return race.distance;
}

void printVehiclesList(const Type& type) {
	if (type == Type::ground) {
		cout << "1. Camel" << endl;
		cout << "2. Horse" << endl;
		cout << "3. Centaur" << endl;
		cout << "4. Boots" << endl;
		cout << "0. To finish selection" << endl;
	} else if (type == Type::air) {
		cout << "1. FlyingCarpet" << endl;
		cout << "2. Eagle" << endl;
		cout << "3. Broom" << endl;
		cout << "0. To finish selection" << endl;
	} else if (type == Type::mixed) {
		cout << "1. Camel" << endl;
		cout << "2. Horse" << endl;
		cout << "3. Centaur" << endl;
		cout << "4. Boots" << endl;
		cout << "5. FlyingCarpet" << endl;
		cout << "6. Eagle" << endl;
		cout << "7. Broom" << endl;
		cout << "0. To finish selection" << endl;
	}
}

enum class RaceReadiness { Yes = 1, No };

bool checkRaceReadiness() {
	int choice{};
	while (cin >> choice && choice != (int)RaceReadiness::Yes || choice != (int)RaceReadiness::No) {
		switch (choice) {
			case (static_cast<int>(RaceReadiness::Yes)):
				return true;
			case (static_cast<int>(RaceReadiness::No)):
				return false;
			default:
				cout << "Nice try ... but wrong!" << endl;
				cout << "Try again: ";
				break;
		}
	}
}

bool isAvailable(Race& race, string name) {
	if (!race.vehicles.empty()) {
		for (Vehicle &vehicle : race.vehicles) {
			if (vehicle.getName() == name) {
				return false;
			}
		}
	}
	return true;
}

vector<Vehicle> chooseVehicles(Race& race) {
	int choise = NULL;
	const size_t min_vehicles_in_race = 2;
	//const int max_ground_vehicles = 4;
	//const int max_air_vehicles = 3;
	//const int max_mixed_vehicles = max_ground_vehicles + max_air_vehicles;
	if (race.type == Type::ground) {
		while (cout << "Enter your choice (number) here: " && cin >> choise && choise != 0) {
			if (static_cast<GroundVehiclesList>(choise) == GroundVehiclesList::Camel) {
				if (isAvailable(race, "Camel")) {
					cout << "Awesome! Camel is now at the start!" << endl;
					Camel camel;
					race.vehicles.push_back(camel);
				} else {
					cout << "Wow...wow...wow, we already have one Camel at the start line, enough!" << endl;
				}
			} else if (static_cast<GroundVehiclesList>(choise) == GroundVehiclesList::Horse) {
				if (isAvailable(race, "Horse")) {
					cout << "Awesome! Horse is now at the start!" << endl;
					Horse horse;
					race.vehicles.push_back(horse);
				} else {
					cout << "Wow...wow...wow, we already have one Horse at the start line, enough!" << endl;
				}
			} else if (static_cast<GroundVehiclesList>(choise) == GroundVehiclesList::Centaur) {
				if (isAvailable(race, "Centaur")) {
					cout << "Awesome! Centaur is now at the start!" << endl;
					Centaur centaur;
					race.vehicles.push_back(centaur);
				} else {
					cout << "Wow...wow...wow, we already have one Centaur at the start line, enough!" << endl;
				}
			} else if (static_cast<GroundVehiclesList>(choise) == GroundVehiclesList::Boots) {
				if (isAvailable(race, "Boots")) {
					cout << "Awesome! Boots are now at the start!" << endl;
					Boots boots;
					race.vehicles.push_back(boots);
				} else {
					cout << "Wow...wow...wow, we already have one Boots at the start line, enough!" << endl;
				}
			} else {
				cout << "Hmmm...I don't see any of this on the list, and you?\nYou can better, try again!" << endl;
			}
		}
	}
	else if (race.type == Type::air) {
		while (cout << "Enter your choice here: " && cin >> choise && choise != 0) {
			if (static_cast<AirVehiclesList>(choise) == AirVehiclesList::FlyingCarpet) {
				if (isAvailable(race, "FlyingCarpet")) {
					cout << "Awesome! FlyingCarpet is now at the start!" << endl;
					FlyingCarpet flying_carpet;
					race.vehicles.push_back(flying_carpet);
				} else {
					cout << "Wow...wow...wow, we already have one FlyingCarpet at the start line, enough!" << endl;
				}
			} else if (static_cast<AirVehiclesList>(choise) == AirVehiclesList::Eagle) {
				if (isAvailable(race, "Eagle")) {
					cout << "Awesome! Eagle is now at the start!" << endl;
					Eagle eagle;
					race.vehicles.push_back(eagle);
				} else {
					cout << "Wow...wow...wow, we already have one Eagle at the start line, enough!" << endl;
				}
			} else if (static_cast<AirVehiclesList>(choise) == AirVehiclesList::Broom) {
				if (isAvailable(race, "Broom")) {
					cout << "Awesome! Broom is now at the start!" << endl;
					Broom broom;
					race.vehicles.push_back(broom);
				} else {
					cout << "Wow...wow...wow, we already have one Broom at the start line, enough!" << endl;
				}
			} else {
				cout << "Hmmm...I don't see any of this on list, and you?\nYou can better, try again!" << endl;
			}
		}
	}
	else if (race.type == Type::mixed) {
		while (cout << "Enter your choice here: " && cin >> choise && choise != 0) {
			if (static_cast<MixedVehiclesList>(choise) == MixedVehiclesList::Camel) {
				if (isAvailable(race, "Camel")) {
					cout << "Awesome! Camel is now at the start!" << endl;
					Camel camel;
					race.vehicles.push_back(camel);
				} else {
					cout << "Wow...wow...wow, we already have one Camel at the start line, enough!" << endl;
				}
			}
			else if (static_cast<MixedVehiclesList>(choise) == MixedVehiclesList::Horse) {
				if (isAvailable(race, "Horse")) {
					cout << "Awesome! Horse is now at the start!" << endl;
					Horse horse;
					race.vehicles.push_back(horse);
				} else {
					cout << "Wow...wow...wow, we already have one Horse at the start line, enough!" << endl;
				}
			}
			else if (static_cast<MixedVehiclesList>(choise) == MixedVehiclesList::Centaur) {
				if (isAvailable(race, "Centaur")) {
					cout << "Awesome! Centaur is now at the start!" << endl;
					Centaur centaur;
					race.vehicles.push_back(centaur);
				} else {
					cout << "Wow...wow...wow, we already have one Centaur at the start line, enough!" << endl;
				}
			}
			else if (static_cast<MixedVehiclesList>(choise) == MixedVehiclesList::Boots) {
				if (isAvailable(race, "Boots")) {
					cout << "Awesome! Boots are now at the start!" << endl;
					Boots boots;
					race.vehicles.push_back(boots);
				} else {
					cout << "Wow...wow...wow, we already have one Boots at the start line, enough!" << endl;
				}
			}
			else if (static_cast<MixedVehiclesList>(choise) == MixedVehiclesList::FlyingCarpet) {
				if (isAvailable(race, "FlyingCarpet")) {
					cout << "Awesome! FlyingCarpet is now at the start!" << endl;
					FlyingCarpet flying_carpet;
					race.vehicles.push_back(flying_carpet);
				} else {
					cout << "Wow...wow...wow, we already have one FlyingCarpet at the start line, enough!" << endl;
				}
			}
			else if (static_cast<MixedVehiclesList>(choise) == MixedVehiclesList::Eagle) {
				if (isAvailable(race, "Eagle")) {
					cout << "Awesome! Eagle is now at the start!" << endl;
					Eagle eagle;
					race.vehicles.push_back(eagle);
				} else {
					cout << "Wow...wow...wow, we already have one Eagle at the start line, enough!" << endl;
				}
			}
			else if (static_cast<MixedVehiclesList>(choise) == MixedVehiclesList::Broom) {
				if (isAvailable(race, "Broom")) {
					cout << "Awesome! Broom is now at the start!" << endl;
					Broom broom;
					race.vehicles.push_back(broom);
				} else {
					cout << "Wow...wow...wow, we already have one Broom at the start line, enough!" << endl;
				}
			} else {
				cout << "Hmmm...I don't see any of this on list, and you?\nYou can better, try again!" << endl;
			}
		}
	}
	return race.vehicles;
}

vector<pair<string, double>> sortList(vector<pair<string, double>>& results_list) {
	sort(results_list.begin(), results_list.end(),
		[](const pair<string, double>& lhs, const pair<string, double>& rhs) {
			return (lhs.second < rhs.second);
		});
	return results_list;
}

vector<pair<string, double>> conductRace(Race& race) {
	vector<pair<string, double>> results_list = {};
	double time = 0;
	for (Vehicle vehicle : race.vehicles) {
		if (vehicle.getName() == "Camel") {
			double one_range_time = race.distance / vehicle.getSpeed();
			// как дот€нутьс€ до Camel moving_time = 30 ?
			if (one_range_time <= 30) {
				time = one_range_time;
			} else if ((one_range_time > 30) && (one_range_time <= (2 * 30))) {
				// как дот€нутьс€ до first_resting_time = 10 ?
				time = one_range_time + 5;
			} else {
				// как дот€нутьс€ до other_resting_time = 5 ?
				time = (one_range_time + 8 * (one_range_time/30 - 2) + 5);
			}
			results_list.push_back({ vehicle.getName(), time });
		} else if (vehicle.getName() == "Horse") {
			double one_range_time = race.distance / vehicle.getSpeed();
			// как дот€нутьс€ до Horse moving_time = 10 ?
			if (one_range_time <= 10) {
				time = one_range_time;
			} else if ((one_range_time > 10) && (one_range_time <= (2 * 10))) {
				// как дот€нутьс€ до first_resting_time = 5 ?
				time = one_range_time + 5;
			} else if ((one_range_time > (2 * 10)) && (one_range_time <= (3 * 10))) {
				// как дот€нутьс€ до second_resting_time = 6.5 ?
				time = one_range_time + 5 + 6.5;
			} else {
				// как дот€нутьс€ до other_resting_time = 8 ?
				time = (one_range_time + 8 * (one_range_time/10 - 3) + 5 + 6.5);
			}
			results_list.push_back({ vehicle.getName(), time });
		} else if (vehicle.getName() == "Centaur") {
			double one_range_time = race.distance / vehicle.getSpeed();
			// как дот€нутьс€ до Centaur moving_time = 8 ?
			if (one_range_time <= 8) {
				time = one_range_time;
			} else {
				// как дот€нутьс€ до resting_time = 2 ?
				time = one_range_time + 2 * (one_range_time/8 - 1);
			}
			results_list.push_back({ vehicle.getName(), time });
		} else if (vehicle.getName() == "Boots") {
			double one_range_time = race.distance / vehicle.getSpeed();
			// как дот€нутьс€ до Boots moving_time = 60 ?
			if (one_range_time <= 60) {
				time = one_range_time;
			} else if ((one_range_time > 60) && (one_range_time <= (2 * 60))) {
				// как дот€нутьс€ до first_resting_time = 10 ?
				time = one_range_time + 10;
			} else {
				// как дот€нутьс€ до other_resting_time = 5 ?
				time = (one_range_time + 5 * (one_range_time/60 - 2) + 10);
			}
			results_list.push_back({ vehicle.getName(), time });
		} else if (vehicle.getName() == "FlyingCarpet") {
			//time = ();
			results_list.push_back({ vehicle.getName(), time });
		} else if (vehicle.getName() == "Eagle") {
			//time = ();
			results_list.push_back({ vehicle.getName(), time });
		} else if (vehicle.getName() == "Broom") {
			//time = ();
			results_list.push_back({ vehicle.getName(), time });
		}
	}
	return sortList(results_list);
}

int main(int argc, char** argv) {
	int play_again = 1;
	while (play_again == 1) {
		Race race;
		cout << "Welcome to the Race Simulation!" << endl;
		cout << "Today we have the following races." << endl;
		cout << "1. Ground Race." << endl;
		cout << "2. Air Race." << endl;
		cout << "3. Mixed Race." << endl;
		cout << endl;
		cout << "Pick up one from the list: ";
		race.type = chooseRaceType(race);
		cout << endl;
		cout << "Enter the Race distance: ";
		race.distance = enterRaceDistance(race);
		cout << endl << "Now, let's select participants! Pick up at least two from the list:" << endl;
		printVehiclesList(race.type);
		race.vehicles = chooseVehicles(race);
		cout << endl << "Ok, all participients have been chosen and are at the start line!" << endl;

		cout << "Psss ... last chance to add some more participants or let's start the Race:" << endl;
		cout << "1. Add more participants." << endl;
		cout << "2. Start the Race." << endl;
		cout << "Make your choice: ";
		race.readiness = checkRaceReadiness();

		if (race.readiness) {
			cout << endl << "Right, let's take another look at our participants!" << endl;
			printVehiclesList(race.type);
			race.vehicles = chooseVehicles(race);
		}

		cout << endl << "Race results:" << endl;
		vector<pair<string, double>> results_list = conductRace(race);

		int counter = 0;
		for (const auto& elm : results_list) {
			cout << ++counter << ". " << elm.first << " - " << elm.second << " hours" << endl;
		}
		
		if (0) {
			cout << race.vehicles[0].getName();

			cout << endl;
			Vehicle vehicle;
			cout << "Name: " << vehicle.getName() << endl;

			GroundVehicle ground_vehicle;
			cout << "Name: " << ground_vehicle.getName() << " | "
				<< "Speed: " << ground_vehicle.getSpeed() << " | "
				<< "Moving Time: " << ground_vehicle.movingTime() << endl;

			Camel camel;
			cout << "Name: " << camel.getName() << " | "
				<< "Speed: " << camel.getSpeed() << " | "
				<< "Moving Time: " << camel.movingTime() << " | "
				<< "Resting Time 1: " << camel.firstRestingTime() << " | "
				<< "Resting Time 2: " << camel.otherRestingTime() << endl;

			Horse horse;
			cout << "Name: " << horse.getName() << " | "
				<< "Speed: " << horse.getSpeed() << " | "
				<< "Moving Time: " << horse.movingTime() << " | "
				<< "Resting Time 1: " << horse.firstRestingTime() << " | "
				<< "Resting Time 2: " << horse.secondRestingTime() << " | "
				<< "Other Resting Time: " << horse.otherRestingTime() << endl;

			Centaur centaur;
			cout << "Name: " << centaur.getName() << " | "
				<< "Speed: " << centaur.getSpeed() << " | "
				<< "Moving Time: " << centaur.movingTime() << " | "
				<< "Resting Time: " << centaur.restingTime() << endl;

			Boots boots;
			cout << "Name: " << boots.getName() << " | "
				<< "Speed: " << boots.getSpeed() << " | "
				<< "Moving Time: " << boots.movingTime() << " | "
				<< "Resting Time 1: " << boots.firstRestingTime() << " | "
				<< "Resting Time 2: " << boots.otherRestingTime() << endl;

			AirVehicle air_vehicle;
			cout << "Name: " << air_vehicle.getName() << " | "
				<< "Speed: " << air_vehicle.getSpeed() << endl;

			Eagle eagle;
			cout << "Name: " << eagle.getName() << " | "
				<< "Speed: " << eagle.getSpeed() << " | "
				<< "Coefficient: " << eagle.getReductionFactor() << endl;

			FlyingCarpet flying_carpet;
			cout << "Name: " << flying_carpet.getName() << " | "
				<< "Speed: " << flying_carpet.getSpeed() << " | "
				<< "Coefficient: " << flying_carpet.getReductionFactor1000() << endl;
		}

		cout << endl << "Wanna play one more time?" << endl;
		cout << "1. Yes" << endl;
		cout << "2. No" << endl;
		cout << "Enter here: ";
		cin >> play_again;
	}
	cout << "\nGAME OVER\n";
	
	return EXIT_SUCCESS;
}