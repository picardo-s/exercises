#include <iostream>

class Matrix
{
private:
    static constexpr int LIM = 10;
    int m_arr[LIM][LIM];
    int m_row;
    int m_column;
    void check_bounds(int a, int b) const
    {
        if ((a < 0 || a >= m_row) || (b < 0 || b >= m_column))
            throw std::runtime_error("Out of bounds!");
    }
public:
    Matrix(int row = LIM, int column = LIM)
        : m_row(row), m_column(column)
    {
        check_bounds(--row, --column);
        for (int i = 0; i < m_row; i++)
            for (int j = 0; j < m_column; j++)
                m_arr[i][j] = 0;
        std::cout << "The [" << m_row << " x " << m_column << "] matrix was created.\n";
    }

    void put_element(int row, int column, int num)
    {
        check_bounds(row, column);
        m_arr[row][column] = num;
    }

    int get_element(int row, int column) const
    {
        check_bounds(row, column);
        return m_arr[row][column];
    }

    int get_row() const
    {
        return m_row;
    }

    int get_column() const
    {
        return m_column;
    }
};

int main()
{
    try
    {
        Matrix matr(3, 4);

        for (int i = 0; i < matr.get_row(); i++)
        {
            for (int j = 0; j < matr.get_column(); j++)
                std::cout << matr.get_element(i, j) << " ";
            std::cout << '\n';
        }

        int temp = 12345;
        matr.put_element(1, 3, temp);
        std::cout << matr.get_element(1, 3) << '\n';
        matr.get_element(6, 6);
    }
    catch (std::exception e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}
