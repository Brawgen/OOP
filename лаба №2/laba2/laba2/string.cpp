#include <string>
#include "string.h"

String::String(std::string FileName)
{
	std::ifstream file(FileName);
	if (file.is_open())
	{
		std::string str;
		bool first_line = 1;
		bool security = 1;

		while (std::getline(file, str))
		{
			std::istringstream flow(str);
			std::vector<double> rows;
			double value;

			while (flow >> value)
			{
				rows.push_back(value);
			}
			if (first_line)
			{
				column = rows.size();
				first_line = 0;
			}
			if (rows.size() == column)
			{
				matr.push_back(rows);
			}
			else
			{
				std::cout << "Ошибка.";
				security = 0;
			}
		}
		this->line = matr.size();
		if (matr.size() > 0)
		{
			this->column = matr[0].size();
		}
		if (security == 0)
		{
			matr.clear();
			this->line = 0;
			this->column = 0;
		}
		file.close();
	}
	else
	{
		std::cout << "Ошибка чтения файла." << "\n";
		system("pause");
		exit(0);
	}
}

String::String()
{
	std::vector
}
