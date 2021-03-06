#include <iostream>
#include <cstring>

using namespace std;

struct Queue {
    int info;
    Queue* next;
} *beginQueue, * endQueue;


Queue* InQueue(Queue* p, int in) {
    Queue* t = new Queue;
    t->info = in;
    t->next = p;
    return t;
}


void viewQueue(Queue* p) {
    Queue* t = p;
    while (t != NULL) {
        cout << " " << t->info << endl;
        t = t->next;
    }
}


void delQueue(Queue** p) {
    while (*p != NULL) {
        endQueue = *p;
        *p = (*p)->next;
        delete endQueue;
    }
}

void Sort_p(Queue* p)
{
    Queue* t = NULL, * t1;
    int r;

    do
    {
        for (t1 = p; t1->next != t; t1 = t1->next)

            if (t1->info > t1->next->info)
            {
                r = t1->info;
                t1->info = t1->next->info;
                t1->next->info = r;
            }
        t = t1;
    } while (p->next != t);
}


int main()
{
    setlocale(LC_ALL, "Russian");

    int i, in, n, command;

    while (true) {
        system("cls");

        cout << "\n1. Создать очередь."
            "\n2. Добавить элементы в очередь."
            "\n3. Посмотреть очередь."
            "\n4. ХАЧУ ЧТОБ СПИСРК СОРТИРОВАЛСЯ."
            "\n5. Удалить очередь."
            "\n0. Выход.\n" << endl;
        cin >> command;
        switch (command) {
        default:
            cout << "Неизвестная команда" << endl;
            break;

        case 1: case 2:

            if (command == 1 && beginQueue != NULL) {
                cout << "Очистка памяти" << endl;

                system("pause");
                break;
            }
            cout << "Введите кол-во элементов: ";
            cin >> n;
            for (i = 1; i <= n; i++) {
                in = rand() % 100 - 60;
                beginQueue = InQueue(beginQueue, in);
            }
            if (command == 1)
                cout << "Создано " << n << " эл." << endl;
            else cout << "Добавлено " << n << " эл." << endl;

            system("pause");
            break;

        case 3:
            if (!beginQueue) {
                cout << "Очередь пуста!" << endl;

                system("pause");
                break;
            }

            cout << "\n---Queue---" << endl;
            viewQueue(beginQueue);

            system("pause");
            break;

        case 4:
            if (!beginQueue) {
                cout << " пуст!" << endl;

                system("pause");
                break;
            }

            Sort_p(beginQueue);

            system("pause");
            break;

        case 5:
            delQueue(&beginQueue);
            cout << "Память чиста!" << endl;

            system("pause");
            break;

        case 0:
            if (beginQueue != NULL)
                delQueue(&beginQueue);

            system("pause");
            return 0;
        }
    }


}

//sus