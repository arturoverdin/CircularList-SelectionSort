#include <fstream>
#include <sstream>

#include "duck_duck_goose.h"

using namespace std;

/* simulates one round of duck duck goose */
void simulateDDGRound(GameData* gamedata, std::ostream& output) {

	size_t goose_index = rand()%(4*gamedata->playerList.size());
	int goose_id = gamedata->playerList.get(goose_index);

	for(size_t i = 0; i < goose_index; i++) {
		int curr = gamedata->playerList.get(i);
		output << "Player " << curr << " is a Duck." << endl;

		if(i == goose_index-1) {
			output << "Player " << gamedata->playerList.get(i+1) 
			<< " is a Goose!" << endl;
		}
	}
	
	int it_roll = (rand()%49)+1;
	int goose_roll = (rand())%49+1;

	while(it_roll == goose_roll) {
		it_roll = (rand()%49)+1;
		goose_roll = (rand())%49+1; 
	}	

	if(it_roll > goose_roll) {

		int temp_id = gamedata->itPlayerID;
		gamedata->itPlayerID = goose_id;
		gamedata->playerList.set(goose_index, temp_id);

		output << temp_id << " took " << goose_id << "'s spot!" << endl;

	} else {
		
		size_t new_it_index = rand()%(gamedata->playerList.size());
		int new_it_id = gamedata->playerList.get(new_it_index);

		if(gamedata->playerList.size() > 1) {	

			while(new_it_id == goose_id) {
				new_it_index = rand()%(gamedata->playerList.size());		
				new_it_id = gamedata->playerList.get(new_it_index);
			}

			gamedata->playerList.remove(new_it_index);
			output << gamedata->itPlayerID << " is out!" << endl;
			gamedata->itPlayerID = 	new_it_id;
			output << new_it_id << " was chosen as the new it." << endl;

		} else {

			output << gamedata->itPlayerID << " is out!" << endl;	
			gamedata->itPlayerID = 0;		
			output << "Winner is " << new_it_id << "."<< endl;
		}		
	}
}

/* initializes values for the simulateDDGRound function and
calls the function until the game is complete */
int main(int argc, char* argv[]) {
	GameData* data = new GameData();

	if(argc < 3) {
		cout << "Please provide a config file and output file" << endl;
		return 0;
	}

	fstream infile;
	infile.open(argv[1]);

	if(infile.fail()){
		cout << "failed to open file" << endl;
		return 0;
	}

	string line;
	stringstream ss;
	
	while(getline(infile, line)) {
		ss << line << " ";
	}

	unsigned int seed;
	int num_players;
	int it_id;

	ss >> seed;
	ss >> num_players;
	ss >> it_id;

	srand(seed);

	data->itPlayerID = it_id;
	
	for(int i = 0; i < num_players-1; i++) {
		int id;
		ss >> id;
		data->playerList.push_back(id);
	}

	infile.close();

	filebuf fb;
	fb.open(argv[2], ios::out);
	ostream output(&fb);

	while(data->itPlayerID != 0) 
		simulateDDGRound(data, output);

	fb.close();

	delete data;
	return 0;
}