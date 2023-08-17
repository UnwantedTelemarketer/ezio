#include "ezio.h"

int main() {
	//Try to read the data from the file, unless it doesnt exist, in which it will print out file doesnt exist.
	//It will also give you a bunch of bad values as to not crash the program.
	ezio::OpenedData oDat;
	//Takes filename, section, and OpenedData reference
	ezio::GetDataFromFile("people.ez", "BOBERT", &oDat);

	std::cout << oDat.getInt("age") << std::endl;
	std::cout << oDat.getString("name") << std::endl;
	std::cout << oDat.getFloat("money") << std::endl;

	std::cout << "Inventory has " << oDat.getArray("items")[1] + " " << oDat.getArray("items")[0] << std::endl;

	int item_count = 15;

	//Create a SaveData and append values to its dictionaries to be saved.
	ezio::SaveData dat;
	dat.ints.append("age", 35);
	dat.strings.append("name", "John buddy");
	dat.floats.append("money", 150.55f);
	dat.items.append("item_name", item_count);

	//Use SaveDataToFile, which takes the path to save to, a header for sectioning, and the data that you want to save
	ezio::SaveDataToFile("people.ez", "BOBERT", dat);
	std::cout << "Hello World!" << std::endl;
	return 1;
}