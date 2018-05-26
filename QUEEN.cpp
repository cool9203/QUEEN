/*@@�ۤv����k��@�K�ӦZ
  @@���ϥΪ��s�t��k & AG(��Ǻt��k)*/

#include <vector>
#include <iostream>
#include <random>

class QUEEN {
protected:
	std::vector<std::vector<int>> map;
	std::vector<int> _X, _Y;
	int _size;

public:
	QUEEN(int assign) {
		_size = assign;
		restart();
	}


	void restart() {
		_X.clear();
		_Y.clear();
		std::random_device rd; //�Q�εw��t�ε����ȨӨ���
		std::default_random_engine generator(rd()); //��l�ơA�çQ��rd()���ȧ�X�۹������ؤl�X??
		std::uniform_int_distribution<int> distribution(0, _size - 1); //�]�w�d��P�M�w�n���ͤ����������ü� ex:int float..
		int randnumber = distribution(generator);
		for (int i = 0; i < _size; i++)
			_X.push_back(i);
		_Y.push_back(randnumber);
	}


	void ypush() {
		std::random_device rd; //�Q�εw��t�ε����ȨӨ���
		std::default_random_engine generator(rd()); //��l�ơA�çQ��rd()���ȧ�X�۹������ؤl�X??
		std::uniform_int_distribution<int> distribution(0, _size - 1); //�]�w�d��P�M�w�n���ͤ����������ü� ex:int float..
		int randnumber = distribution(generator);
		_Y.push_back(randnumber);
	}


	void set_map() {
		map.clear();
		//��l�ƴѽL
		for (int i = 0; i < _size; i++) {
			std::vector<int> tempv;
			for (int j = 0; j < _size; j++) {
				tempv.push_back(0);
			}
			map.push_back(tempv);
		}

		for (int i = 0; i < static_cast<int>(_X.size()); i++) {
			map[_X.at(i)][_Y.at(i)] = 1;
		}
	}


	void print() {
		set_map();

		for (int i = 0; i < _size; i++) {
			for (int j = 0; j < _size; j++) {
				if (map[i][j] == 1)
					std::cout << "��";
				else
					std::cout << "��";
			}
			std::cout << "\n";
		}
		std::cout << "\n";
	}


	bool price(std::vector<int> x, std::vector<int> y) {
		for (int i = 0; i < static_cast<int>(y.size()); i++) {
			for (int j = i + 1; j < static_cast<int>(y.size()); j++) {
				double _x = x[i] - x[j];
				double _y = y[i] - y[j];
				double m = _y / _x;
				if (_x == 0.0 || _y == 0.0 || m == 1.0 || m == -1.0) {
					return true;
				}
			}
		}

		return false;
	}


	void start() {
		int size = 0, count = 0;
		while (true) {
			if (size != _Y.size()) {
				size = _Y.size();
			}
			else {
				std::cout << "size ="<< size << "\n";
				size = 0;
				count++;
				restart();
				continue;
			}
			
			if (_Y.size() == _size)
				break;

			for (int i = 0; i < _size*5; i++) {
				ypush();
				if (price(_X, _Y)) {
					_Y.pop_back();
				}
				else
					break;
			}
		}
		print();
		std::cout << "\n" << "restart : " << count << "\n";
	}
};


int main() {
	int n;
	std::cin >> n;
	QUEEN queen(n);
	queen.start();

	system("pause");
}
