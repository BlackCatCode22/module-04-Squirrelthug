#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <random>
using namespace std;


class Animal{
private:
    string animalName;
    string animalAge;
    string animalSpecies;
public:
    Animal(string name, string age, string species)
        : animalName(name), animalAge(age), animalSpecies(species) {
    }

    // Virtual destructor
    virtual ~Animal() {}

    // getters
    string getName() const {
        return animalName;
    }

    string getAge() const {
        return animalAge;
    }

    string getSpecies() const {
        return animalSpecies;
    }

    // setters
    void setName(const string &name) {
        this->animalName = name;
    }

    void setAge(const string age) {
        this->animalAge = age;
    }

    void setSpecies(const string &species) {
        this->animalSpecies = species;
    }
};

class Hyena : public Animal{
private:
    string seasonBorn;
    string Gender;
    string Color;
    string Weight;
    string Origin;
public:
    Hyena(string name, string age, string species) : Animal(name, age, species), seasonBorn(""), Gender(""), Color(""), Weight(""), Origin("") {
    }

    // getters
    string getSeasonBorn() const {
        return seasonBorn;
    }

    string getGender() const {
        return Gender;
    }

    string getColor() const {
        return Color;
    }

    string getWeight() const {
        return Weight;
    }

    string getOrigin() const {
        return Origin;
    }

    // setters
    void setSeasonBorn(const string &season) {
        this->seasonBorn = season;
    }

    void setGender(const string &gender) {
        this->Gender = gender;
    }

    void setColor(const string &color) {
        this->Color = color;
    }

    void setWeight(const string &weight) {
        this->Weight = weight;
    }

    void setOrigin(const string &origin) {
        this->Origin = origin;
    }
};

class Tiger : public Animal{
private:
    string seasonBorn;
    string Gender;
    string Color;
    string Weight;
    string Origin;
public:
    Tiger(string name, string age, string species) : Animal(name, age, species), seasonBorn(""), Gender(""), Color(""), Weight(""), Origin("") {
    }

    // getters
    string getSeasonBorn() const {
        return seasonBorn;
    }

    string getGender() const {
        return Gender;
    }

    string getColor() const {
        return Color;
    }

    string getWeight() const {
        return Weight;
    }

    string getOrigin() const {
        return Origin;
    }

    // setters
    void setSeasonBorn(const string &season) {
        this->seasonBorn = season;
    }

    void setGender(const string &gender) {
        this->Gender = gender;
    }

    void setColor(const string &color) {
        this->Color = color;
    }

    void setWeight(const string &weight) {
        this->Weight = weight;
    }

    void setOrigin(const string &origin) {
        this->Origin = origin;
    }
};

class Lion : public Animal{
private:
    string seasonBorn;
    string Gender;
    string Color;
    string Weight;
    string Origin;
public:
    Lion(string name, string age, string species) : Animal(name, age, species), seasonBorn(""), Gender(""), Color(""), Weight(""), Origin("") {
    }

    // getters
    string getSeasonBorn() const {
        return seasonBorn;
    }

    string getGender() const {
        return Gender;
    }

    string getColor() const {
        return Color;
    }

    string getWeight() const {
        return Weight;
    }

    string getOrigin() const {
        return Origin;
    }

    // setters
    void setSeasonBorn(const string &season) {
        this->seasonBorn = season;
    }

    void setGender(const string &gender) {
        this->Gender = gender;
    }

    void setColor(const string &color) {
        this->Color = color;
    }

    void setWeight(const string &weight) {
        this->Weight = weight;
    }

    void setOrigin(const string &origin) {
        this->Origin = origin;
    }
};

class Bear : public Animal{
private:
    string seasonBorn;
    string Gender;
    string Color;
    string Weight;
    string Origin;
public:
    Bear(string name, string age, string species) : Animal(name, age, species), seasonBorn(""), Gender(""), Color(""), Weight(""), Origin("") {
    }

    // getters
    string getSeasonBorn() const {
        return seasonBorn;
    }

    string getGender() const {
        return Gender;
    }

    string getColor() const {
        return Color;
    }

    string getWeight() const {
        return Weight;
    }

    string getOrigin() const {
        return Origin;
    }

    // setters
    void setSeasonBorn(const string &season) {
        this->seasonBorn = season;
    }

    void setGender(const string &gender) {
        this->Gender = gender;
    }

    void setColor(const string &color) {
        this->Color = color;
    }

    void setWeight(const string &weight) {
        this->Weight = weight;
    }

    void setOrigin(const string &origin) {
        this->Origin = origin;
    }
};


int main() {
    ifstream file("../arrivingAnimals.txt");
    vector<Animal*> animals;
    map<string, int> speciesCount;
    ifstream nameFile("../animalNames.txt");
    // TODO: DEBUG AREA - REMOVE LATER
    //
    if (nameFile.is_open()) {
        cout << "File is open" << endl;
    }
    //
    // TODO: END DEBUG AREA
    string listLine;
    vector<string>* currentSpecies = nullptr;
    string line;
    string name;
    vector<string> hyenaNames;
    vector<string> tigerNames;
    vector<string> lionNames;
    vector<string> bearNames;
    // TODO: DEBUG AREA - REMOVE LATER
    //
    cout << "Initial size of hyenaNames: " << hyenaNames.size() << endl;
    cout << "Initial size of tigerNames: " << tigerNames.size() << endl;
    cout << "Initial size of lionNames: " << lionNames.size() << endl;
    cout << "Initial size of bearNames: " << bearNames.size() << endl;
    //
    // TODO: END DEBUG AREA

    // Create a random number engine
    random_device rd;                   // Seed for the random number engine
    default_random_engine engine(rd()); // Use the random device to seed the engine

    // TODO: DEBUG AREA - REMOVE LATER
    //
    nameFile.clear();
    nameFile.seekg(0, ios::beg);
    //
    // TODO: END DEBUG AREA

    // read names from animalNames.txt and populate vector for each animal
    while (getline(nameFile, listLine)) {
        if (listLine.empty() || listLine == " " || listLine == "\n" || listLine == "\r" || listLine == "\r\n") {
            // TODO: DEBUG AREA - REMOVE LATER
            //
            cout << "Line is empty or space" << endl;
            //
            // TODO: END DEBUG AREA
            continue;                   // Skip blank lines and spaces
        }
        // Trim trailing whitespace from the line
        listLine.erase(find_if(listLine.rbegin(), listLine.rend(), [](unsigned char ch) {
            return !isspace(ch);
        }).base(), listLine.end());

        if (listLine.find("Names") != string::npos) {
            // This line is a species name line
            // TODO: DEBUG AREA - REMOVE LATER
            //
            cout << "Species line found" << endl;
            //
            // TODO: END DEBUG AREA
            const string& species = listLine;

            if (species == "Hyena Names:") {
                currentSpecies = &hyenaNames;
            } else if (species == "Tiger Names:") {
                currentSpecies = &tigerNames;
            } else if (species == "Lion Names:") {
                currentSpecies = &lionNames;
            } else if (species == "Bear Names:") {
                currentSpecies = &bearNames;
            }
        } else if (currentSpecies) {
            // This line is a names line
            // TODO: DEBUG AREA - REMOVE LATER
            //
            cout << "Names line found" << endl;
            //
            // TODO: END DEBUG AREA
            istringstream ss(listLine);
            string listName;

            // add to the current species vector
            size_t pos = 0;
            std::string token;
            while ((pos = listLine.find(", ")) != std::string::npos) {
                token = listLine.substr(0, pos);
                listLine.erase(0, pos + 2); // +2 because we have ", "
                currentSpecies->push_back(token);
            }
            currentSpecies->push_back(listLine); // Push back the last name
        }

        }

    // TODO: DEBUG AREA - REMOVE LATER
    //
    cout << "Size of hyenaNames after population: " << hyenaNames.size() << endl;
    cout << "Hyena Names: " << endl;
    for(const auto& name : hyenaNames) {
        cout << name << endl;
    }
    cout << "Size of tigerNames after population: " << tigerNames.size() << endl;
    cout << "Tiger Names: " << endl;
    for(const auto& name : tigerNames) {
        cout << name << endl;
    }
    cout << "Size of lionNames after population: " << lionNames.size() << endl;
    cout << "Lion Names: " << endl;
    for(const auto& name : lionNames) {
        cout << name << endl;
    }
    cout << "Size of bearNames after population: " << bearNames.size() << endl;
    cout << "Bear Names: " << endl;
    for(const auto& name : bearNames) {
        cout << name << endl;
    }
    //
    // TODO: END DEBUG AREA

    // Randomize the order of the names
    shuffle(hyenaNames.begin(), hyenaNames.end(), engine);
    shuffle(tigerNames.begin(), tigerNames.end(), engine);
    shuffle(lionNames.begin(), lionNames.end(), engine);
    shuffle(bearNames.begin(), bearNames.end(), engine);

    nameFile.close();                   // Close the file after reading the names


    // read the animal attributes from arrivingAnimals.txt and create respective objects
    while (getline(file, line)) {
        istringstream ss(line);
        string age, gender, species, seasonBorn, color, weight, origin;

        // read the first five words
        for (int i = 0; i < 3; i++) {   // first three for age
            string word;
            getline(ss, word, ' ');
            age += word + " ";
        }
        // TODO: DEBUG AREA - REMOVE LATER
        //
        cout << "Age: " << age << endl;
        //
        // TODO: END DEBUG AREA
        getline(ss, gender, ' ');       // next for gender
        // TODO: DEBUG AREA - REMOVE LATER
        //
        cout << "Gender: " << gender << endl;
        //
        // TODO: END DEBUG AREA
        getline(ss, species, ',');      // last for species
        // TODO: DEBUG AREA - REMOVE LATER
        //
        cout << "Species: " << species << endl;
        //
        // TODO: END DEBUG AREA


        // read the rest of the attributes
        getline(ss, seasonBorn, ',');
        // TODO: DEBUG AREA - REMOVE LATER
        //
        cout << "Season Born: " << seasonBorn << endl;
        //
        // TODO: END DEBUG AREA
        getline(ss, color, ',');
        // TODO: DEBUG AREA - REMOVE LATER
        //
        cout << "Color: " << color << endl;
        //
        // TODO: END DEBUG AREA
        getline(ss, weight, ',');
        // TODO: DEBUG AREA - REMOVE LATER
        //
        cout << "Weight: " << weight << endl;
        //
        // TODO: END DEBUG AREA
        getline(ss, origin, ',');
        // TODO: DEBUG AREA - REMOVE LATER
        //
        cout << "Origin: " << origin << endl;
        //
        // TODO: END DEBUG AREA

        Animal* animal;
        if (species == "hyena") {
            name = hyenaNames.back();   // use final name in array
            hyenaNames.pop_back();      // remove final name from array
            animal = new Hyena(name,
                               age,
                               species);// create new animal object
            speciesCount[species]++;    // increment the respective animal count in map
        } else if (species == "tiger") {
            name = tigerNames.back();
            tigerNames.pop_back();
            animal = new Tiger(name,
                               age,
                               species);
            speciesCount[species]++;
        }   else if (species == "lion") {
            name = lionNames.back();
            lionNames.pop_back();
            animal = new Lion(name,
                              age,
                              species);
            speciesCount[species]++;
        }   else if (species == "bear") {
            name = bearNames.back();
            bearNames.pop_back();
            animal = new Bear(name,
                              age,
                              species);
            speciesCount[species]++;
        }

        // Use dynamic cast to set the attributes of the animal
        if (Hyena* hyena = dynamic_cast<Hyena*>(animal)) {
            hyena->setSeasonBorn(seasonBorn);
            hyena->setGender(gender);
            hyena->setColor(color);
            hyena->setWeight(weight);
            hyena->setOrigin(origin);
        } else if (Tiger* tiger = dynamic_cast<Tiger*>(animal)) {
            tiger->setSeasonBorn(seasonBorn);
            tiger->setGender(gender);
            tiger->setColor(color);
            tiger->setWeight(weight);
            tiger->setOrigin(origin);
        } else if (Lion* lion = dynamic_cast<Lion*>(animal)) {
            lion->setSeasonBorn(seasonBorn);
            lion->setGender(gender);
            lion->setColor(color);
            lion->setWeight(weight);
            lion->setOrigin(origin);
        } else if (Bear* bear = dynamic_cast<Bear*>(animal)) {
            bear->setSeasonBorn(seasonBorn);
            bear->setGender(gender);
            bear->setColor(color);
            bear->setWeight(weight);
            bear->setOrigin(origin);
        }

        animals.push_back(animal);

        // TODO: DEBUG AREA - REMOVE LATER
        //
        for (const auto &pair : speciesCount) {
            cout << "Species " << pair.first << ": " << "Count " << pair.second << endl;
        }
        //
        // TODO: END DEBUG AREA
    }

    file.close();

}

