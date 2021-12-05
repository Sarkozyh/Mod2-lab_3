#include<stdio.h>
#include<malloc.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS

struct Data
{
    char name[16];
    int price;
    int quantity;
    int nds;
};

void save(struct Data data[], int size) {                   //Функция, сохраняющая изменения в файлах
    FILE* fp;
    FILE* sfp;
    if ((sfp = fopen("Size.txt", "w")) == NULL)             //Открыите файла для записи и его очистка 
    {
        perror("Error occured while opening file");
        return 1;
    }
    fprintf(sfp, "%i", size);                               //Запись нового значения в файл
    fclose(sfp);                                            //Закрытие файла
    if ((fp = fopen("Data.txt", "w")) == NULL)              //Очитска файла
    {
        perror("Error occured while opening file");
        return 1;
    }
    fclose(fp);                                              //Закрытие файла
    if ((fp = fopen("Data.txt", "a")) == NULL)              //Открытие файла для добавление записей в его конец
    {
        perror("Error occured while opening file");
        return 1;
    }
    for (int i = 0; i < size; i++) {                        //Запись новых данных в файл
        fprintf(fp, "%s %i %i %i\n", data[i].name, data[i].price, data[i].quantity, data[i].nds);
    }
    fclose(fp);
}

void findByName(char name[], struct Data data[], int size, int nameSize) {      //Поиск по имени
    int matchingMax = 0;
    int index = 0;
    int found = 0;
    for (int i = 0; i < size; i++) {
    int matching = 0;
    int strSize = nameSize;
    size_t a = sizeof(data->name) / sizeof(char);
    size_t b = sizeof(name) / sizeof(name[0]);
    if (sizeof(data->name) / sizeof(char) < sizeof(name) / sizeof(char)) {
        strSize = sizeof(data->name) / sizeof(char);
    }
    else {
        sizeof(name) / sizeof(char);
    }
        for (int j = 0; j < strSize; j++) {
            if (data[i].name[j] == name[j]) {
                matching++;
            }
        }
        if (matching > matchingMax) {
            matchingMax = matching;
            index = i;
        }
        if (matching == sizeof(data->name) / sizeof(char)) {
            found = 1;
            printf("%s %i %i %i\n", data[i].name, data[i].price, data[i].quantity, data[i].nds);
        }
    }
    if(found == 0)
        printf("%s %i %i %i\n", data[index].name, data[index].price, data[index].quantity, data[index].nds);
}

void findByPrice(int price, struct Data data[], int size) {             //Поиск по цене
    int closest = 100000000;
    int pozition = -1;
    
    for (int i = 0; i < size; i++) {
        
        if (data[i].price == price) {
            printf("%s %i %i %i\n", data[i].name, data[i].price, data[i].quantity, data[i].nds);
        }
        else {
            if (abs(data[i].price - price) < closest) {
                closest = abs(data[i].price - price);
                pozition = i;
            }
        }
    }
    if (pozition >= 0) {
        printf("%s %i %i %i\n", data[pozition].name, data[pozition].price, data[pozition].quantity, data[pozition].nds);
    }
}

void findByQuantity(int quantity, struct Data data[], int size) {           //Поиск по количеству
    int closest = 100000000;
    int pozition = -1;

    for (int i = 0; i < size; i++) {

        if (data[i].quantity == quantity) {
            printf("%s %i %i %i\n", data[i].name, data[i].quantity, data[i].quantity, data[i].nds);
        }
        else {
            if (abs(data[i].quantity - quantity) < closest) {
                closest = abs(data[i].quantity - quantity);
                pozition = i;
            }
        }
    }
    if (pozition >= 0) {
        printf("%s %i %i %i\n", data[pozition].name, data[pozition].price, data[pozition].quantity, data[pozition].nds);
    }
}

void findByNDS(int nds, struct Data data[], int size) {             //Поиск по налогу
    int closest = 100000000;
    int pozition = -1;

    for (int i = 0; i < size; i++) {

        if (data[i].nds == nds) {
            printf("%s %i %i %i\n", data[i].name, data[i].nds, data[i].nds, data[i].nds);
        }
        else {
            if (abs(data[i].nds - nds) < closest) {
                closest = abs(data[i].nds - nds);
                pozition = i;
            }
        }
    }
    if (pozition >= 0) {
        printf("%s %i %i %i\n", data[pozition].name, data[pozition].price, data[pozition].quantity, data[pozition].nds);
    }
}

void sortByQuantity(struct Data* data, int size)            //Сортировка по количеству         
{
    // Для всех элементов
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = (size - 1); j > i; j--) 
        {
            if (data[j - 1].quantity > data[j].quantity) 
            {
                struct Data temp = data[j - 1]; 
                data[j - 1] = data[j];
                data[j] = temp;
            }
        }
    }
    save(data, size);
}

void sortByNDS(struct Data* data, int size)         //Сортировка по налогу
{
   
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = (size - 1); j > i; j--) 
        {
            if (data[j - 1].nds > data[j].nds) 
            {
                struct Data temp = data[j - 1];
                data[j - 1] = data[j];
                data[j] = temp;
            }
        }
    }
    save(data, size);
}

void sortByName(struct Data* data, int size)        //Сортировка по имени
{

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = (size - 1); j > i; j--)
        {
            if (data[j - 1].name[0] > data[j].name[0]) 
            {
                struct Data temp = data[j - 1]; 
                data[j - 1] = data[j];
                data[j] = temp;
            }
        }
    }
    save(data, size);
}

void sortByPrice(struct Data* data, int size)                 //Сортировка  по цене
{
   
    for (int i = 0; i < size - 1; i++) 
    {
        for (int j = (size - 1); j > i; j--) 
        {
            if (data[j - 1].price > data[j].price) 
            {
                struct Data temp = data[j - 1]; 
                data[j - 1] = data[j];
                data[j] = temp;
            }
        }
    }
    save(data, size);
}

int add(struct Data* d, int* size) {                            //Добавление элементов в конец файла
    FILE* fp;
    
    int quantity = *size;
    *size = quantity + 1;
    if ((fp = fopen("Data.txt", "a")) == NULL)
    {
        perror("Error occured while opening file");
        return 1;
    }
    fprintf(fp, "%s %i %i %i\n", d->name, d->price, d->quantity, d->nds);
    fclose(fp);

    if ((fp = fopen("Size.txt", "w")) == NULL)
    {
        perror("Error occured while opening file");
        return 1;
    }
    fprintf(fp, "%i", *size);
    fclose(fp);
}

struct Data* load(int* size) {                                  //Загрузка данных из файла
    FILE* fpSize;
    if ((fpSize = fopen("Size.txt", "r")) == NULL)
    {
        perror("Error occured while opening file");
        return 1;
    }
    int quantity = 0;
    int temp = 0;
    while (fscanf(fpSize, "%d", &temp) == 1)
        quantity += temp;
    *size = quantity;
    fclose(fpSize);
    FILE* fp;
    if ((fp = fopen("Data.txt", "r")) == NULL)
    {
        perror("Error occured while opening file");
        return 1;
    }
    char c = 0;
    int i = 0;
    int j = 0;
   
    struct Data* d = (struct Data*)malloc(sizeof(struct Data) * quantity);
    while (j < quantity)
    {
        while ((c = fgetc(fp)) != ' ' && i < 16) {
            d[j].name[i] = c;
            i++;
        }
        d[j].name[i] = '\0';
        d[j].price = 0;
        while ((c = fgetc(fp)) != ' ') {
            d[j].price =  c - 48 + d[j].price * 10;
        }
        d[j].quantity = 0;
        while ((c = fgetc(fp)) != ' ') {
            d[j].quantity = d[j].quantity * 10 + c - 48;
        }
        d[j].nds = 0;
        while ((c = fgetc(fp)) != '\n' && c  != EOF) {
            d[j].nds = d[j].nds  * 10 + c - 48;
        }
        j++;
        i = 0;
    }
    fclose(fp);
    fclose(fpSize);
    return d;
}

void removeLine(struct Data* data, int* size, int index) {                          //Удаление записи из файла
    
   
    struct Data* tmp = (struct Data*)malloc(sizeof(struct Data) * (*size - 1));
    int j = 0;
    for (int i = 0; i < *size; i++) {
        if (i != index) {
            tmp[j] = data[i];
            j++;
        }
    }
    for (int i = 0; i < *size - 1; i++) {
        data[i] = tmp[i];
    } 
    *size = *size - 1;
    save(data, *size);
}

void edit(struct Data* data ,int index, int size) {
    if (index < size) {
        printf("Enter new name: ");
        scanf("%s", data[index].name);
        printf("Enter new price: ");
        scanf("%i", &data[index].price);
        printf("Enter new quantity: ");
        scanf("%i", &data[index].quantity);
        printf("Enter new nds: ");
        scanf("%i", &data[index].nds);
        save(data, size);
    }
    else
    {
        printf("Error! Wrong index!");
    }
}

float averagePrice(struct Data* data, int size) {                           //Поиск средней цены
    float res = 0;
    for (int i = 0; i < size; i++) {
        res += data[i].price;
    }
    res = res / size;
    return res;
}

void show(struct Data* data, int size) {                                    //Вывод таблицы на экран
    printf("---------------------------------------------------------\n");
    for (int i = 0; i < size; i++) {
        printf("| %s | %i | %i | %i |\n", data[i].name, data[i].price, data[i].quantity, data[i].nds);
        printf("---------------------------------------------------------\n");
    }
}

/*
*/

int main() {
    struct Data dataAdd;
    int size = 0;
    struct Data* data = load(&size);
    int option = 0;
    while (option != 9) {
        printf("1) Add to table\n2) Save table\n3) Show table\n4) Sort table\n5) Edit line\n6) Revove line\n7) Find average price\n8) Search\n9) Exit\n");
        scanf("%i", &option);
        switch (option) {
        case 1:
            printf("Enter the name: ");
            scanf("%s", dataAdd.name);
            printf("Enter the price: ");
            scanf("%i", &dataAdd.price);
            printf("Enter the quantity: ");
            scanf("%i", &dataAdd.quantity);
            printf("Enter the nds: ");
            scanf("%i", &dataAdd.nds);
            add(&dataAdd, &size);
            data = load(&size);
            show(data, size);
            break;
        case 2:
            save(data, size);
            show(data, size);
            break;

        case 3:
            show(data, size);
            break;
        case 4:
            printf("Choose a field:\n 1) Name\n 2) Price\n 3) Quantity\n 4) NDS\n");
            int sort = 0;
            scanf("%i", &sort);
            switch (sort) {
            case 1:
                sortByName(data, size);
                break;
            case 2:
                 sortByPrice(data, size);
                 break;
            case 3:
                sortByQuantity(data, size);
                break;
            case 4:
                sortByNDS(data, size);
                break;
            }
            show(data, size);
            break;
        case 5:
            printf("Enter the index: ");
            int index = 0;
            scanf("%i", &index);
            if (index < 0 || index >= size) {
                printf("Error! Wrong index!");
            }
            else{
                edit(data, index, size);
            }
            show(data, size);
            break;
        case 6:
            printf("Enter the index: ");
            int ind = 0;
            scanf("%i", &ind);
            if (ind < 0 || ind >= size) {
                printf("Error! Wrong index!");
            }
            else {
                removeLine(data, &size, ind);
                save(data, size);
            }
            show(data, size);
            break;
        case 7:
            float res = averagePrice(data, size);
            printf("%f\n", res);
            break;
        case 8:
            printf("Choose a field:\n 1) Name\n 2) Price\n 3) Quantity\n 4) NDS\n");
            int search = 0;
            scanf("%i", &search);
            switch (search) {
            case 1:
                printf("Enter the name\n");
                char name[20];
                scanf("%s", name);
                int nameSize = sizeof(name) / sizeof(char);
                findByName(name, data, size, nameSize);
                break;
            case 2:
                printf("Enter the price\n");
                int price = 0;
                scanf("%i", &price);
                findByPrice(price, data, size);
                break;
            case 3:
                printf("Enter the quantity\n");
                int quantity = 0;
                scanf("%i", &quantity);
                findByQuantity(quantity, data, size);
                break;
            case 4:
                printf("Enter the NDS\n");
                int nds = 0;
                scanf("%i", &nds);
                findByNDS(nds, data, size);
                break;
            
            }
        case 9:
        break;
        }
    }

    //printf("%f", averagePrice(data, size));
    //edit(data, 0, size);
    //add(&dataAdd, &size);
    //removeLine(data, &size, 0);
    //sortByName(data, size);
    //findByName("Appleeeee", data, &size);
    //save(&data);
  //  for (int i = 0; i < size; i++){
       // printf("%s %i %i %i\n", data[i].name, data[i].price, data[i].quantity, data[i].nds);
    //}
    data = NULL;
    free(data);
    return 0;
}