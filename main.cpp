#include <iostream>
#include <string>
#include <vector>

//represents a single cell in the spreadsheet
class Cell {
private:
    std::string m_value;

public:
    Cell() = default;
    Cell(const std::string& value) : m_value(value) {}

    int to_Int() const {
        return std::stoi(m_value);
    }

    double to_Double() const {
        return std::stod(m_value);
    }

    std::string to_string() const {
        return m_value;
    }

    void SetValue(const std::string& value) {
        m_value = value;
    }
};

//represents the entire spreadsheet
class SpreadSheet {
private:
    int row;
    int column;
    Cell** m_cells;

public:
	//constructor
    SpreadSheet(const int row, const int column) : row(row), column(column) {
        m_cells = new Cell*[row];
        for (int i = 0; i < row; ++i) {
            m_cells[i] = new Cell[column];
        }
    }

	//destructor dor deallocating the memory 
    ~SpreadSheet() {
        for (int i = 0; i < row; ++i) {
            delete[] m_cells[i];
        }
        delete[] m_cells;
    }

	//getters
    int GetRow() const{
        return row;
    }

    int GetColumn() const{
        return column;
    }
	
	//getting the value at the specified location
    Cell GetValue(int row, int column) const{
        if (row >= 0 && row < this->row && column >= 0 && column < this->column) {
            return m_cells[row][column];
        } else {
            std::cout << "Error: Cell index out of range" << std::endl;
            return Cell();
        }
    }
	
	//setting the value at the specified location
    void SetValue(int row, int column, const std::string& value) {
        if (row >= 0 && row < this->row && column >= 0 && column < this->column) {
            m_cells[row][column].SetValue(value);
        } else {
            std::cout << "Error: Cell index out of range" << std::endl;
        }
    }

	//tester function for spreadsheet 
    void TesterOfCells() const{
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                Cell cell = m_cells[i][j];
                std::string value = cell.to_string();
                if (!value.empty()) {
                    std::cout << "The element at (" << i << " , " << j << ") is " << value << std::endl;
                }else{
					std::cout << "The element at (" << i << " , " << j << ") is empty " << std::endl;
				}
            }
        }
    }
};

int main() {
	//creating the size of spreadsheet 2x3
    SpreadSheet sheet(2, 3);

	//importing 2 elements
    sheet.SetValue(1, 2, "43");
	sheet.SetValue(1, 1, "2");

	//convert string to int
    std::cout << sheet.GetValue(1, 2).to_Int() << std::endl;

	//testing whether the cells are empty or not?
    sheet.TesterOfCells();

    return 0;
}

