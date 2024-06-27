#include <iostream> 
#include <algorithm> // для swap. У C++11 використовуйте заголовок <utility>

using namespace std;

int main()
{
	const int length = 5;
	int array[length] = { 30, 50, 20, 10, 40 };

	cout << "old massiv: ";
	for (int index = 0; index < length; ++index)
		cout << array[index] << ' ';
	cout << endl << endl;

	// Перебираємо кожен елемент масиву (крім останнього, він вже буде відсортований до того часу, коли ми до нього дійдемо)
	for (int startIndex = 0; startIndex < length - 1; ++startIndex)
	{
		// У змінній smallestIndex зберігається індекс найменшого значення, яке ми знайшли в поточній ітерації.
		// Починаємо з того, що найменший елемент в цій ітерації - це перший елемент (індекс 0)
		int smallestIndex = startIndex;

		// Потім шукаємо менший елемент в іншій частині масиву
		for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
		{
			// Якщо ми знайшли елемент, який менше нашого найменшого елементу,
			if (array[currentIndex] < array[smallestIndex])
				// то запам'ятовуємо його
				smallestIndex = currentIndex;
		}

		// smallestIndex тепер найменший елемент.
		// Міняємо місцями наше початкове найменше число з тим, яке ми виявили
		swap(array[startIndex], array[smallestIndex]);
	}

	cout << "new massiv: ";

	// Тепер, коли весь масив відсортований - виводимо його на екран
	for (int index = 0; index < length; ++index)
		cout << array[index] << ' ';

	cout << endl;

	return 0;
}