#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>

int main()
{
	setlocale(LC_ALL, "Russian");
	std::cout << "Для работы с программой используйте полноэкранный режим!";
	std::this_thread::sleep_for(std::chrono::seconds(4));
	system("cls");
	std::cout << "Режим строительства препятствий. Для изменения режима на снегопад нажмите Enter. Поставить наклонённую вправо крышу - нажать 2 , Поставить прямое препятствие(_) - нажать 1. Изменение положения курсора стрелочками "<< '\n';
	std::cout << "ВНИМАНИЕ: строить на 49 и 50 высоте НЕЛЬЗЯ!";
	std::this_thread::sleep_for(std::chrono::seconds(7));
	system("cls");
	int matrix[50][50] = { 0 };
	int position[2] = { 0,0 };
	matrix[position[1]][position[0]] = 1;
	int ch;
	do
	{
		bool temporal;
		system("cls");
		for (int i = 0; i < 50; ++i)
		{
			for (int g = 0; g < 50; ++g)
			{
				if (matrix[i][g] == 1)
				{
					std::cout << '^';
				}
				if (matrix[i][g] == 0)
				{
					std::cout << ' ';
				}
				if (matrix[i][g] == 2)
				{
					std::cout << '\\';
				}
				if (matrix[i][g] == -1)
				{
					std::cout << '*';
				}
				if (matrix[i][g] == 3)
				{
					std::cout << '_';
				}

			}
			std::cout << '\n';
		}
		ch = _getch();
		if (ch == 224)
		{
			switch (_getch())
			{
			case 75:
				if (position[0] != 0 && (matrix[position[1]][position[0]-1] !=3) && (matrix[position[1]][position[0] - 1] != 2))
				{
					matrix[position[1]][position[0]] = 0;
					position[0] -= 1;
					matrix[position[1]][position[0]] = 1;
				}
				break;
			case 77:
				if (position[0] != 50 && (matrix[position[1]][position[0] + 1] != 3) && (matrix[position[1]][position[0] + 1] != 2))
				{
					matrix[position[1]][position[0]] = 0;
					position[0] += 1;
					matrix[position[1]][position[0]] = 1;
				}
				break;
			case 72:
				if (position[1] != 0 && (matrix[position[1] - 1][position[0]] != 3) && (matrix[position[1] - 1][position[0]] != 2))
				{
					matrix[position[1]][position[0]] = 0;
					position[1] -= 1;
					matrix[position[1]][position[0]] = 1;
				}
				break;
			case 80:
				if (position[1] != 50 && (matrix[position[1] + 1][position[0]] != 3) && (matrix[position[1] + 1][position[0]] != 2))
				{
					matrix[position[1]][position[0]] = 0;
					position[1] += 1;
					matrix[position[1]][position[0]] = 1;
				}
				break;
			}
		}
		if (ch == '1')
		{
			temporal = 0;
			if (position[1] > 1)
			{
				matrix[position[1]][position[0]] = 3;
				if (matrix[position[1] - 1][position[0]] == 0 && temporal == 0)
				{
					matrix[position[1] - 1][position[0]] = 1;
					position[1] = position[1] - 1;
					temporal = 1;
				}
				if (matrix[position[1]][position[0] + 1] == 0 && temporal == 0)
				{
					matrix[position[1]][position[0] + 1] = 1;
					position[0] = position[0] + 1;
					temporal = 1;
				}
				if (matrix[position[1] + 1][position[0]] == 0 && temporal == 0)
				{
					matrix[position[1] + 1][position[0]] = 1;
					position[1] = position[1] + 1;
					temporal = 1;
				}
				if (matrix[position[1]][position[0] - 1] == 0 && temporal == 0)
				{
					matrix[position[1]][position[0] - 1] = 1;
					position[0] = position[0] - 1;
					temporal = 1;
				}
			}
		}
		if (ch == '2')
		{
			temporal = 0;
			if (position[1] > 1)
			{
				matrix[position[1]][position[0]] = 2;
				if (matrix[position[1] - 1][position[0]] == 0 && temporal == 0)
				{
					matrix[position[1] - 1][position[0]] = 1;
					position[1] = position[1] - 1;
					temporal = 1;
				}
				if (matrix[position[1]][position[0] + 1] == 0 && temporal == 0)
				{
					matrix[position[1]][position[0] + 1] = 1;
					position[0] = position[0] + 1;
					temporal = 1;
				}
				if (matrix[position[1] + 1][position[0]] == 0 && temporal == 0)
				{
					matrix[position[1] + 1][position[0]] = 1;
					position[1] = position[1] + 1;
					temporal = 1;
				}
				if (matrix[position[1]][position[0] - 1] == 0 && temporal == 0)
				{
					matrix[position[1]][position[0] - 1] = 1;
					position[0] = position[0] - 1;
					temporal = 1;
				}
			}
		}
	} 
	while (ch != 13);
	matrix[position[1]][position[0]] = 0;
	position[1] = 0;
	matrix[position[1]][position[0]] = 1;
	std::cout << "Режим снегопада. Для сброса снежинки нажмите пробел, изменение курсора стрелочками(влево и вправо). Падает только 1 снежинка!";
	std::this_thread::sleep_for(std::chrono::seconds(3));
	do
	{
		system("cls");
		for (int i = 0; i < 50; ++i)
		{
			for (int g = 0; g < 50; ++g)
			{
				if (matrix[i][g] == 1)
				{
					std::cout << '^';
				}
				if (matrix[i][g] == 0)
				{
					std::cout << ' ';
				}
				if (matrix[i][g] == 2)
				{
					std::cout << '\\';
				}
				if (matrix[i][g] == -1)
				{
					std::cout << '*';
				}
				if (matrix[i][g] == 3)
				{
					std::cout << '_';
				}

			}
			std::cout << '\n';
		}
		ch = _getch();
		if (ch == 224)
		{
			switch (_getch())
			{
			case 75:
				if (position[0] != 0)
				{
					matrix[position[1]][position[0]] = 0;
					position[0] -= 1;
					matrix[position[1]][position[0]] = 1;
				}
				break;
			case 77:
				if (position[0] != 50)
				{
					matrix[position[1]][position[0]] = 0;
					position[0] += 1;
					matrix[position[1]][position[0]] = 1;
				}
				break;

			}

		}
		if (ch == ' ')
		{
			matrix[(position[1] + 1)][position[0]] = -1;
			bool returnmark = 0;
			while ( returnmark != 1 )
			{
				for (int i = 0; i < 49; ++i)
				{
						if (matrix[i][position[0]] == -1 && matrix[i + 1][position[0]] == 3)
						{
							returnmark = 1;
						}
						if (matrix[i][position[0]] == -1 && matrix[i + 1][position[0]] == 2 && matrix[i][position[0] + 1] == 2 )
						{
							returnmark = 1;
						}
						if (matrix[i][position[0]] == -1 && matrix[i + 1][position[0]] == 2 && matrix[i][position[0] + 1] == -1)
						{
							returnmark = 1;
						}
						if (matrix[i][position[0]] == -1 && matrix[i + 1][position[0]] == -1 && matrix[i + 1][position[0] - 1] == -1 && matrix[i + 1][position[0] + 1] == -1)
						{
							returnmark = 1;
						}
						if (matrix[i][position[0]] == -1 && matrix[i + 1][position[0]] == 2 && matrix[i + 1][position[0] + 1] == 3)
						{
							matrix[i][position[0]] = 0;
							matrix[position[1]][position[0]] = 0;
							position[0] = position[0] + 1;
							matrix[position[1]][position[0]] = 1;
							matrix[i][position[0]] = -1;
							returnmark = 1;
						}
						if (matrix[i][position[0]] == -1 && matrix[i + 1][position[0]] == 2 && matrix[i][position[0] + 1] == 0)
						{
							matrix[i][position[0]] = 0;
							matrix[position[1]][position[0]] = 0;
							position[0] = position[0] + 1;
							matrix[position[1]][position[0]] = 1;
							matrix[i][position[0]] = -1;
						}
						if (matrix[i][position[0]] == -1 && matrix[i + 1][position[0]] == -1 && matrix[i + 1][position[0] + 1] == 0)
						{
							matrix[i][position[0]] = 0;
							matrix[position[1]][position[0]] = 0;
							position[0] = position[0] + 1;
							matrix[position[1]][position[0]] = 1;
							matrix[i][position[0]] = -1;
						}
						if (matrix[i][position[0]] == -1 && matrix[i + 1][position[0]] == -1 && matrix[i + 1][position[0] - 1] == 0)
						{
							matrix[i][position[0]] = 0;
							matrix[position[1]][position[0]] = 0;
							position[0] = position[0] - 1;
							matrix[position[1]][position[0]] = 1;
							matrix[i][position[0]] = -1;
						}
						if (matrix[48][position[0]] == -1)
						{
							matrix[i + 1][position[0]] = -1;
							matrix[i][position[0]] = 0;
							returnmark = 1;
						}
						if (matrix[i][position[0]] == -1 && returnmark == 0)
						{
							matrix[i + 1][position[0]] = -1;
							matrix[i][position[0]] = 0;
						}
						if (returnmark == 0)
						{


							system("cls");
							for (int i = 0; i < 50; ++i)
							{
								for (int g = 0; g < 50; ++g)
								{
									if (matrix[i][g] == 1)
									{
										std::cout << '^';
									}
									if (matrix[i][g] == 0)
									{
										std::cout << ' ';
									}
									if (matrix[i][g] == 2)
									{
										std::cout << '\\';
									}
									if (matrix[i][g] == -1)
									{
										std::cout << '*';
									}
									if (matrix[i][g] == 3)
									{
										std::cout << '_';
									}

								}
								std::cout << '\n';
							}
						}
				}
			}
		}

	} while (ch != 27);
}