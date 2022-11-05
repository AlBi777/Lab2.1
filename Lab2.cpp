
struct camera
{
	int main_camera;
	int front_camera;
};

struct battery
{
	int capacity;
	char *type;
};

struct memory
{
	int ram;
	int rom;
};

struct screen {
	int diagonal;
	char* type;
};

struct system
{
	char name;
	int version;
};

struct smartphone
{
	struct camera camera_get;
	struct battery battery_get;
	struct memory memory_get;
	struct screen screen_get;
	struct system system_get;
};

