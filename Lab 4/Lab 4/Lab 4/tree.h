typedef struct tree {
	char* mark;
	struct tree* left;
	struct tree* right;
}tree;


tree* create(char* w, FILE* file);
void add(tree* current_node, char* new_question, char* new_object, FILE* file);

tree* insert(FILE* file);
void ask(tree* tree, FILE* file);
tree* load_tree(FILE* file);
void save_tree(FILE* file, tree* current_node);
