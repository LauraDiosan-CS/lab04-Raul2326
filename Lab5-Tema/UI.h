#include <string>
#include <cstring>
#include <sstream>
#include <cctype>
#include <iterator>
#include <vector>
#include <stdio.h>
#include <ctime>
#include "Expense.h"
#include "Service.h"
using namespace std;

class UI {
private:
	Service S;
	void Menu();
	//--------------------------------------------------------------------
	void Add();
	void Delete();
	void Update();
	//--------------------------------------------------------------------
	void DelDay();
	void DelRange();
	void DelType();
	//--------------------------------------------------------------------
	void ShowAll();
	void ShowType();
	void ShowTGM();
	void ShowTEM();
	//--------------------------------------------------------------------
	void SumByType();
	void MaxDayBySum();
	void SortDS();
	void SortDST();
	//--------------------------------------------------------------------
	void FilterType();
	void FilterTypeLM();
	void FilterTypeEM();
	//--------------------------------------------------------------------
	vector<string> ParsCommand();
	void HandleCLI(vector<string>tokens);
	void Undo();
public:
	UI();
	~UI();
	void Run();
};