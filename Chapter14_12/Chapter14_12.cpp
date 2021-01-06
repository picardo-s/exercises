#include <iostream>
#include <fstream>
#include <string>

constexpr int MAX = 100;

class DoFile
{
private:
    std::fstream file;
public:
    DoFile(const std::string& file_name)
    {
        file.open(file_name, std::ios::trunc | std::ios::in | std::ios::out | std::ios::binary);
        if (!file)
            throw FileException("Cannot open the file");
    }

    void write(int* buff, int size)
    {
        std::cout << "\nWriting...";
        file.write(reinterpret_cast<char*>(buff), size * sizeof(int));
        if (!file)
            throw FileException("Cannot write the file");
    }

    void read(int* buff, int size)
    {
        std::cout << "\nReading...";
        file.read(reinterpret_cast<char*>(buff), size * sizeof(int));
        if (!file)
            throw FileException("Cannot read the file");
    }

    void zero_file_position()
    {
        file.seekg(0);
    }

    ~DoFile()
    {
        file.close();
    }

    class FileException
    {
    public:
        const std::string str_err;
        FileException(const char err[]) : str_err(err)
        {}
    };
};

int main()
{
    int buff[MAX];
    std::string str;

    for (int i = 0; i < MAX; i++)
        buff[i] = i;

    std::cout << "Enter a file\'s name: ";
    std::getline(std::cin, str);

    try
    {
        DoFile df(str);
        df.write(buff, MAX);

        for (int i = 0; i < MAX; i++)
            buff[i] = 0;

        df.zero_file_position();
        df.read(buff, MAX);

        for (int i = 0; i < MAX; i++)
        {
            std::cout << buff[i] << " ";
            if (buff[i] != i)
                throw std::runtime_error("Wrong data");
        }
    }
    catch (DoFile::FileException& e)
    {
        std::cout << "Exception: " << e.str_err;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what();
    }
}
