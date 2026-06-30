#include <iostream>
#include <cstring>
using namespace std;

//1
class Laptop {
private:
	char* _brand;
	double _price;
public:
	Laptop(const char* brand, double price) {
		_price = price;
		_brand = new char[strlen(brand) + 1];
		strcpy_s(_brand, strlen(brand) + 1, brand);
	}

	~Laptop() {
		delete[] _brand;
	}

	void Info() {
		cout << "Brand: " << _brand << "\nPrice: " << _price << endl;
	}
};



//2
class Playlist {
private:
	char** _songs;
	int _capacity;
	int _count;
public:
	Playlist(int maxSongs) {
		_capacity = maxSongs;
		_count = 0;
		_songs = new char* [_capacity];
	}
	void addSong(const char* songName) {
		if (_count >= _capacity)
		{
			cout << "Playlist is full" << endl;
			return;
		}
		_songs[_count] = new char[strlen(songName) + 1];
		strcpy_s(_songs[_count], strlen(songName) + 1, songName);
		_count++;
		cout << "Added " << songName << " to the playlist!" << endl;
	}

	~Playlist()
	{
		for (int i = 0; i < _count; i++)
		{
			delete[] _songs[i];
		}
		delete[] _songs;
	}

	void show() {
		cout << "Playlist:" << endl;
		for (int i = 0; i < _count; i++)
		{
			cout << i + 1 << ". " << _songs[i] << endl;
		}
	}
};


int main() {
	//1
	Laptop laptop1("Acer", 1199.99);
	laptop1.Info();

	//2
	Playlist liked(3);
	liked.addSong("Kittens");
	liked.addSong("Puppies");
	liked.addSong("Lions");
	liked.addSong("Dolphins");
	liked.show();




	return 0;
}