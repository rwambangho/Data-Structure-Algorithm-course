#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORD_SIZE 1000
#define MAX_MEANING_SIZE 1000
#define DATASET_SIZE 1000

typedef struct {
    char word[MAX_WORD_SIZE];
    char meaning[MAX_MEANING_SIZE];
} element;

element dictionary[DATASET_SIZE];
int current_size = 0;

// ���� �����ͼ� ����
void generate_dataset() {
    const char* words[] = { "jacket", "chair", "desk", "apple", "flower", "grape", "house", "banana", "ice", "elephant",
    "car", "dog", "cat", "tree", "sun", "moon", "computer", "book", "phone", "keyboard",
    "television", "monitor", "mouse", "tablet", "lamp", "bag", "shirt", "pants", "shoes",
    "coffee", "tea", "water", "juice", "wine", "beer", "cake", "cookie", "bread", "butter",
    "pizza", "hamburger", "sandwich", "soda", "cheese", "egg", "chicken", "beef", "pork",
    "fish", "salad", "apple", "orange", "grape", "pineapple", "mango", "banana", "peach",
    "cherry", "strawberry", "blueberry", "blackberry", "lemon", "lime", "apricot", "plum",
    "melon", "watermelon", "kiwi", "pear", "fig", "date", "papaya", "passionfruit", "pomegranate",
    "avocado", "coconut", "carrot", "potato", "tomato", "onion", "garlic", "spinach", "lettuce",
    "cucumber", "bell pepper", "zucchini", "pumpkin", "broccoli", "cauliflower", "asparagus",
    "eggplant", "corn", "peas", "beans", "peanuts", "lentils", "chickpeas", "rice", "wheat",
    "barley", "oats", "soy", "tofu", "seitan", "quinoa", "spaghetti", "noodles", "pasta",
    "ramen", "sushi", "tacos", "burrito", "falafel", "hummus", "shawarma", "pizza", "pasta",
    "burger", "hotdog", "french fries", "onion rings", "tater tots", "potato wedges", "fried chicken",
    "steak", "roast beef", "grilled chicken", "bbq ribs", "fish and chips", "lasagna", "casserole",
    "pie", "cake", "cupcake", "muffin", "brownie", "cookie", "biscuit", "donut", "croissant",
    "bagel", "toast", "pancake", "waffle", "cereal", "oatmeal", "yogurt", "cheese", "butter",
    "cream", "milk", "whipped cream", "ice cream", "sherbet", "frozen yogurt", "sorbet", "gelato",
    "chocolate", "candy", "gum", "popcorn", "chips", "pretzels", "crackers", "cheese puffs",
    "fruit snack", "granola", "trail mix", "nut", "peanut butter", "jam", "jelly", "honey",
    "maple syrup", "vinegar", "soy sauce", "hot sauce", "mustard", "ketchup", "mayonnaise",
    "salad dressing", "spice", "salt", "pepper", "garlic powder", "onion powder", "cumin",
    "coriander", "paprika", "turmeric", "curry", "chili powder", "basil", "oregano", "parsley",
    "rosemary", "thyme", "oregano", "sage", "mint", "chili flakes", "cinnamon", "nutmeg",
    "cloves", "cardamom", "allspice", "vanilla", "ginger", "almonds", "cashews", "walnuts",
    "pistachios", "hazelnuts", "peanuts", "sunflower seeds", "pumpkin seeds", "chia seeds",
    "flax seeds", "sesame seeds", "coconut flakes", "dried fruit", "raisins", "cranberries",
    "blueberries", "apricots", "mango", "papaya", "coconut", "dates", "figs", "caramel",
    "marzipan", "fudge", "truffle", "tart", "pie", "cake", "cookie", "pudding", "jelly",
    "mousse", "cream puff", "eclair", "tiramisu", "cheesecake", "baklava", "custard",
    "churros", "doughnuts", "gelato", "frozen yogurt", "sorbet", "ice cream", "sundae",
    "smoothie", "milkshake", "juice", "water", "soda", "coffee", "tea", "beer", "wine",
    "champagne", "whiskey", "vodka", "rum", "gin", "tequila", "brandy", "cognac", "liqueur",
    "cocktail", "martini", "margarita", "mojito", "cosmopolitan", "pina colada", "bloody mary",
    "gin and tonic", "beer", "lager", "pilsner", "stout", "porter", "ale", "IPA", "wheat beer",
    "saison", "trappist beer", "sake", "soju", "vodka", "tequila", "rum", "whiskey", "bourbon",
    "scotch", "brandy", "cognac", "liqueur", "absinthe", "mead", "cocktail", "beer", "wine",
    "liquor", "liquorice", "cheese", "yogurt", "milk", "butter", "cream", "whipped cream" };
    const char* meanings[] = {
         "����", "����", "å��", "���", "��", "����", "��", "�ٳ���", "����", "�ڳ���",
    "��", "��", "�����", "����", "�¾�", "��", "��ǻ��", "å", "��ȭ", "Ű����",
    "�ڷ�����", "�����", "���콺", "�º�", "����", "����", "����", "����", "�Ź�",
    "Ŀ��", "��", "��", "�ֽ�", "����", "����", "����ũ", "��Ű", "��", "����",
    "����", "�ܹ���", "������ġ", "�Ҵ�", "ġ��", "���", "ġŲ", "�Ұ��", "�������",
    "�����", "������", "���", "������", "����", "���ξ���", "����", "�ٳ���", "������",
    "ü��", "����", "��纣��", "������", "����", "����", "�챸", "�ڵ�",
    "���", "����", "Ű��", "��", "��ȭ��", "����", "���ľ�", "�м�����Ʈ", "����",
    "�ƺ�ī��", "���ڳ�", "���", "����", "�丶��", "����", "����", "�ñ�ġ", "����",
    "����", "�Ǹ�", "ȣ��", "����ݸ�", "�ݸ��ö��", "�ƽ��Ķ�Ž�", "����",
    "������", "�ϵ���", "��", "����", "������", "���Ƹ���", "��", "��",
    "����", "�͸�", "��", "�κ�", "����ź", "�����", "���İ�Ƽ", "��", "�Ľ�Ÿ",
    "���", "�ʹ�", "Ÿ��", "�θ���", "�ȶ���", "�Ĺ���", "���͸���", "����", "�Ľ�Ÿ",
    "����", "�ֵ���", "����ġ������", "���ĸ�", "Ÿ����", "�������� ����", "Ƣ�� ġŲ",
    "������ũ", "�ν�Ʈ ����", "���� ġŲ", "BBQ ��", "�ǽþ�Ĩ��", "���ڳ�", "ī����",
    "����", "����ũ", "������ũ", "����", "�����", "��Ű", "��Ŷ", "����",
    "ũ�οͻ�", "���̱�", "�佺Ʈ", "������ũ", "����", "�ø���", "��Ʈ��", "���Ʈ",
    "ġ��", "����", "ũ��", "����", "����ũ��", "���̽�ũ��", "�Ź�", "�õ� ���Ʈ",
    "�Ҹ���", "������", "���ݸ�", "ĵ��", "��", "����", "Ĩ", "������", "ũ��Ŀ",
    "ġ�� ����", "���� ����", "�׷����", "Ʈ���� �ͽ�", "�߰���", "�ǳӹ���", "��", "����",
    "��", "������ �÷�", "����", "����", "�ּҽ�", "�ӽ��͵�", "��ø", "�������",
    "������ �巹��", "��ŷ�", "�ұ�", "����", "���ð���", "���İ���", "Ŀ��",
    "���", "������ī", "��Ȳ", "ī��", "ĥ���Ŀ��", "����", "��������", "�Ľ���",
    "�����", "Ÿ��", "������", "��Ʈ", "ĥ�� �÷���ũ", "����", "���α�",
    "����", "ī�ٸ�", "�ý����̽�", "�ٴҶ�", "����", "�Ƹ��", "ĳ����", "ȣ��",
    "�ǽ�Ÿġ��", "�������", "����", "�عٶ�⾾", "ȣ�ھ�", "ġ�ƾ�",
    "�Ƹ���", "����", "���ڳ� �÷���ũ", "���� ����", "������", "ũ������",
    "��纣��", "�챸", "����", "���ľ�", "���ڳ�", "����", "��ȭ��", "ī���",
    "������", "Ǫ��", "����", "����", "ũ�� ����", "��Ŭ����", "Ƽ��̼�", "ġ������ũ",
    "��Ŭ���", "Ŀ���͵�", "��ν�", "����", "������", "�õ� ���Ʈ", "�Ҹ���",
    "���̽�ũ��", "����", "������", "��ũ����ũ", "�ֽ�", "��", "�Ҵ�", "Ŀ��", "��", "����",
    "����", "������", "����Ű", "����ī", "��", "��", "��ų��", "�귣��", "�ڳ�", "��ť��",
    "Ĭ����", "��Ƽ��", "������Ÿ", "������", "�ڽ�������ź", "�ǳ� �ݶ��", "���� �޸�",
    "�� ���", "����", "���", "�ʽ���", "��Ÿ��Ʈ", "����", "����", "IPA", "�и���",
    "����", "Ʈ���ǽ�Ʈ ����", "����", "����", "����ī", "��ų��", "��", "����Ű", "����",
    "��īġ", "�귣��", "�ڳ�", "��ť��", "�Ѽ���", "�޵�", "Ĭ����", "����", "����", "�ַ�"
         };
    int dataset_size = sizeof(words) / sizeof(words[0]);
    for (int i = 0; i < dataset_size; i++) {
        strncpy(dictionary[current_size].word, words[i], MAX_WORD_SIZE - 1);
        strncpy(dictionary[current_size].meaning, meanings[i], MAX_MEANING_SIZE - 1);
        current_size++;
    }
}

// ���� ���
void print_dictionary(element dict[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%s: %s\n", dict[i].word, dict[i].meaning);
    }
}

// ���� ����
void bubble_sort(element list[], int n) {
    element temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(list[j].word, list[j + 1].word) > 0) {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}

// ���� ����
void insertion_sort(element list[], int n) {
    element key;
    int j;
    for (int i = 1; i < n; i++) {
        key = list[i];
        j = i - 1;
        while (j >= 0 && strcmp(list[j].word, key.word) > 0) {
            list[j + 1] = list[j];
            j--;
        }
        list[j + 1] = key;
    }
}

// �� ����
int partition(element list[], int left, int right) {
    element pivot = list[left];
    int low = left + 1;
    int high = right;
    element temp;

    while (low <= high) {
        while (low <= right && strcmp(list[low].word, pivot.word) <= 0) low++;
        while (high >= left && strcmp(list[high].word, pivot.word) > 0) high--;
        if (low < high) {
            temp = list[low];
            list[low] = list[high];
            list[high] = temp;
        }
    }
    temp = list[left];
    list[left] = list[high];
    list[high] = temp;
    return high;
}

void quick_sort(element list[], int left, int right) {
    if (left < right) {
        int q = partition(list, left, right);
        quick_sort(list, left, q - 1);
        quick_sort(list, q + 1, right);
    }
}

int main() {
    clock_t start, end;

    generate_dataset();
   //printf("���� �� ����:\n");
    //print_dictionary(dictionary, current_size);

    // ���� ����
    start = clock();
    bubble_sort(dictionary, current_size);
    end = clock();
    printf("\n���� ���� �ҿ� �ð�: %lf��\n", (double)(end - start) / CLOCKS_PER_SEC);

    // ���� �� ���
    //printf("\n���� �� ����:\n");
    //print_dictionary(dictionary, current_size);

    // �ٸ� ���� �˰��� ���� �׽�Ʈ
    generate_dataset(); // �ʱ�ȭ
    start = clock();
    insertion_sort(dictionary, current_size);
    end = clock();
    printf("\n���� ���� �ҿ� �ð�: %lf��\n", (double)(end - start) / CLOCKS_PER_SEC);

    generate_dataset(); // �ʱ�ȭ
    start = clock();
    quick_sort(dictionary, 0, current_size - 1);
    end = clock();
    printf("\n�� ���� �ҿ� �ð�: %lf��\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
