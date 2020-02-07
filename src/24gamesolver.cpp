#include <chrono> // Untuk menghitung waktu
#include <iostream> // Untuk input/output
#include <string> // Untuk proses tipe data string
using namespace std;

// Inisialisasi variabel
string str; // Variabel string untuk membentuk string ekpresi aritmatika
string op = "+-*/"; // Variabel untuk menampung seluruh operator aritmatika
int number[4]; // Variabel untuk menampung seluruh angka yang diinput
double result; // Variabel untuk hasil perhitungan aritmatika
int solution_counter = 0; // Variabel untuk menghitung jumlah solusi
const char* expression_string;	// Variabel untuk string ekspresi aritmatika yang 
								// akan diparse menggunakan recursive descent parser

//-------------------------Recursive Descent Parser-------------------------
char current_element()
// Fungsi untuk mendapatkan elemen yang diproses
{
	return *expression_string;
}

char advance()
// Fungsi untuk memajukan satu elemen dari string
{
	return *expression_string++;
}

double numbers()
// Fungsi untuk parsing angka
{
	int result = advance() - '0';
	while (current_element() >= '0' && current_element() <= '9')
	{
		result = 10*result + advance() - '0';
	}
	return result;
}

double expression();
//Definisi dari expression() yang akan digunakan dalam fungsi factor()

double factor()
//Fungsi untuk parsing angka, tanda negatif, dan tanda kurung
{
	if (current_element() >= '0' && current_element() <= '9')
	{
		return numbers();
	}
	else if (current_element() == '(')
	{
		advance(); // skip '('
		double result = expression();
		advance(); // skip ')'
		return result;
    }
	else if (current_element() == '-')
	{
		advance(); // skip '-'
		return -factor();
	}
	return 0; // ketika error, langsung return
}

double term()
//Fungsi untuk parsing operator * dan /
{
	double result = factor();
	while (current_element() == '*' || current_element() == '/')
	{
		if (advance() == '*')
		{
			result *= factor();
		}
		else
		{
			result /= factor();
		}
	}
	return result;
}

double expression()
// Fungsi untuk parsing operator + dan -
{
	double result = term();
	while (current_element() == '+' || current_element() == '-')
	{
		if (advance() == '+')
		{
			result += term();
		}
		else
		{
			result -= term();
		}
	}
	return result;
}

//-------------------------Bracket Permutation-------------------------
void bracket_permutation_1(int angka[], int i, int j, int k)
// (n0 op0 n1) op1 (n2 op2 n3)
// n adalah angka, dan op adalah operator
// Contoh: (6 + 6) + (6 + 6)
{
	str = "";
	str.append("(");
	str = str + to_string(angka[0]);
	str.append(op,i,1);
	str = str + to_string(angka[1]);
	str.append(")");
	str.append(op,j,1);
	str.append("(");
	str = str + to_string(angka[2]);
	str.append(op,k,1);
	str = str + to_string(angka[3]);
	str.append(")");
	expression_string = str.c_str();
	result = expression();
	// Evaluasikan permutasi ekspresi aritmatika yang ada, yang diambil hanya yang hasilnya 24
	if ((result > 23.9999999999) && (result < 24.0000000001))
	{
		solution_counter++;
		cout << solution_counter << " " << str << endl;
	}
}

void bracket_permutation_2(int angka[], int i, int j, int k)
// ((n0 op1 n1) op2 n2) op3 n3
// n adalah angka, dan op adalah operator
// Contoh: ((6 + 6) + 6) + 6
{ 
	str = "";
	str.append("(");
	str.append("(");
	str = str + to_string(angka[0]);
	str.append(op,i,1);
	str = str + to_string(angka[1]);
	str.append(")");
	str.append(op,j,1);
	str = str + to_string(angka[2]);
	str.append(")");
	str.append(op,k,1);
	str = str + to_string(angka[3]);
	expression_string = str.c_str();
	result = expression();
	// Evaluasikan permutasi ekspresi aritmatika yang ada, yang diambil hanya yang hasilnya 24
	if ((result > 23.9999999999) && (result < 24.0000000001))
	{
		solution_counter++;
		cout << solution_counter << " " << str << endl;
	}
}

void bracket_permutation_3(int angka[], int i, int j, int k)
// (n0 op0 (n1 op1 n2)) op2 n3
// n adalah angka, dan op adalah operator
// Contoh: (6 + (6 + 6)) + 6
{
	str = "";
	str.append("(");
	str = str + to_string(angka[0]);
	str.append(op,i,1);
	str.append("(");
	str = str + to_string(angka[1]);
	str.append(op,j,1);
	str = str + to_string(angka[2]);
	str.append(")");
	str.append(")");
	str.append(op,k,1);
	str = str + to_string(angka[3]);
	expression_string = str.c_str();
	result = expression();
	// Evaluasikan permutasi ekspresi aritmatika yang ada, yang diambil hanya yang hasilnya 24
	if ((result > 23.9999999999) && (result < 24.0000000001))
	{
		solution_counter++;
		cout << solution_counter << " " << str << endl;
	}
}
	
void bracket_permutation_4(int angka[], int i, int j, int k)
// n0 op0 ((n1 op1 n2) op2 n3)	
// n adalah angka, dan op adalah operator
// Contoh: 6 + ((6 + 6) + 6)
{
	str = "";
	str = str + to_string(angka[0]);
	str.append(op,i,1);
	str.append("(");
	str.append("(");
	str = str + to_string(angka[1]);
	str.append(op,j,1);
	str = str + to_string(angka[2]);
	str.append(")");
	str.append(op,k,1);
	str = str + to_string(angka[3]);
	str.append(")");
	expression_string = str.c_str();
	result = expression();
	// Evaluasikan permutasi ekspresi aritmatika yang ada, yang diambil hanya yang hasilnya 24
	if ((result > 23.9999999999) && (result < 24.0000000001))
	{
		solution_counter++;
		cout << solution_counter << " " << str << endl;
	}
}
	
void bracket_permutation_5(int angka[], int i, int j, int k)
// n0 op1 (n1 op (n2 op3 n3))
// n adalah angka, dan op adalah operator
// Contoh: 6 + (6 + (6 + 6))
{
	str = "";
	str = str + to_string(angka[0]);
	str.append(op,i,1);
	str.append("(");
	str = str + to_string(angka[1]);
	str.append(op,j,1);
	str.append("(");
	str = str + to_string(angka[2]);
	str.append(op,k,1);
	str = str + to_string(angka[3]);
	str.append(")");
	str.append(")");
	expression_string = str.c_str();
	result = expression();
	// Evaluasikan permutasi ekspresi aritmatika yang ada, yang diambil hanya yang hasilnya 24
	if ((result > 23.9999999999) && (result < 24.0000000001))
	{
		solution_counter++;
		cout << solution_counter << " " << str << endl;
	}
}

//-------------------------Enumerasikan Permutasi-------------------------
bool mustSwap(int string[], int begin, int current_string_element) 
// Jika elemen yang sedang diproses tidak sama dengan elemen-elemen setelah awal string, maka harus ditukar (return 1)
// Jika sama, tidak ditukar (return 0)
{ 
	for (int x = begin; x < current_string_element; x++)
	{  
		if (string[x] == string[current_string_element]) 
		{
			return 0; 
		}
	}
	return 1; 
} 
  
void print_permutations(int string[], int current_index, int length_of_string) 
// Print seluruh permutasi string yang mungkin
{ 
    if (current_index >= length_of_string) 
    { 
		for (int x = 0; x <= 3; x++)
		{
			for (int y = 0; y <= 3; y++)
			{
				for (int z = 0; z <= 3; z++)
				{
					bracket_permutation_1(string, x, y, z);
					bracket_permutation_2(string, x, y, z);
					bracket_permutation_3(string, x, y, z);
					bracket_permutation_4(string, x, y, z);
					bracket_permutation_5(string, x, y, z);
				}
			}
		}
		return; 
	} 
  
    for (int i = current_index; i < length_of_string; i++) 
    { 
		// Pengecekan setiap elemen string secara maju, ditentukan elemen harus ditukar atau tidak
		bool check = mustSwap(string, current_index, i); 
		if (check) 
		{ 
			swap(string[current_index], string[i]); 
			print_permutations(string, current_index + 1, length_of_string); 
			swap(string[current_index], string[i]); 
		} 
	} 
} 
  
int main() 
{ 	
	/*
	 ________   _____     ________                          _________      .__                     
	 \_____  \ /  |  |   /  _____/_____    _____   ____    /   _____/ ____ |  |___  __ ___________ 
	 /   ____//   |  |_ /   \  ___\__  \  /     \_/ __ \   \_____  \ /  _ \|  |\  \/ // __ \_  __ \
	/       \/    ^   / \    \_\  \/ __ \|  Y Y  \  ___/   /        (  <_> )  |_\   /\  ___/|  | \/
	\_______ \____   |   \______  (____  /__|_|  /\___  > /_______  /\____/|____/\_/  \___  >__|   
	        \/    |__|          \/     \/      \/     \/          \/                      \/    
	* */
	cout << " ________   _____     ________                          _________      .__                     " << endl;
	cout << " \\_____  \\ /  |  |   /  _____/_____    _____   ____    /   _____/ ____ |  |___  __ ___________" << endl;
	cout << " /   ____//   |  |_ /   \\  ___\\__  \\  /     \\_/ __ \\   \\_____  \\ /  _ \\|  |\\  \\/ // __ \\_  __ \\ " << endl;
	cout << "/       \\/    ^   / \\    \\_\\  \\/ __ \\|  Y Y  \\  ___/   /        (  <_> )  |_\\   /\\  ___/|  | \\/" << endl;
	cout << "\\_______ \\____   |   \\______  (____  /__|_|  /\\___  > /_______  /\\____/|____/\\_/  \\___  >__|   " << endl;
	cout << "        \\/    |__|          \\/     \\/      \\/     \\/          \\/                      \\/       " << endl;
    
	//Input 4 angka
	cout << "By Ignatius Timothy Manullang/13517044" << endl << "Input 4 numbers, one at a time" << endl;
	for(int number_counter = 0; number_counter <= 3; number_counter++)
	{
		cout << "Input number " << number_counter+1 << ": ";
		cin >> number[number_counter];
	}
	auto start = chrono::high_resolution_clock::now(); 	// Set up waktu awal proses
	print_permutations(number, 0, 4);  // Cari permutasi dan tampilkan
	//Tampilkan jumlah solusi 24 game yang dapat ditemukan dari input 4 angka
	if (solution_counter == 0) 
	{
		cout << "NO SOLUTIONS FOUND" << endl;
	}
	else
	{
		cout << "Solutions found: " << solution_counter << endl;
	}
	auto finish = chrono::high_resolution_clock::now(); // Set up waktu akhir proses
	chrono::duration<double> elapsed = finish - start; // Hitung selisih waktu akhir dan awal proses
	cout << "Elapsed time: " << elapsed.count() << " s\n"; // Tampilkan waktu yang dipakai
	return 0; 
} 
