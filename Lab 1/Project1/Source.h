int input();
int input_oper();
int input_size();
int input_sorting();
int input_year();
int input_speed();

void clear_and_stop_console();

typedef struct  {
	char* mark;
	char* country;
	int year;
	int max_speed;
	enum color color;
}car;

enum color {
	RED = 1,
	BLACK = 2,
	WHITE = 3,
};

car* creating_struct(int* size);
void color(int num);

void creating(car* car, int size);
void showing(car* cars, int size);
int main(car* cars);

void sorting_mark(car* cars, int size);
void sorting_country(car* cars, int size);
void sorting_year(car* cars, int size);
void sorting_max_speed(car* cars, int size);
void sorting_color(car* cars, int size);

void deleting(car* cars, int* size);

void freeshka(car* cars, int size);