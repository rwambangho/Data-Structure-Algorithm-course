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

// 임의 데이터셋 생성
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
         "자켓", "의자", "책상", "사과", "꽃", "포도", "집", "바나나", "얼음", "코끼리",
    "차", "개", "고양이", "나무", "태양", "달", "컴퓨터", "책", "전화", "키보드",
    "텔레비전", "모니터", "마우스", "태블릿", "램프", "가방", "셔츠", "바지", "신발",
    "커피", "차", "물", "주스", "와인", "맥주", "케이크", "쿠키", "빵", "버터",
    "피자", "햄버거", "샌드위치", "소다", "치즈", "계란", "치킨", "소고기", "돼지고기",
    "물고기", "샐러드", "사과", "오렌지", "포도", "파인애플", "망고", "바나나", "복숭아",
    "체리", "딸기", "블루베리", "블랙베리", "레몬", "라임", "살구", "자두",
    "멜론", "수박", "키위", "배", "무화과", "대추", "파파야", "패션프루트", "석류",
    "아보카도", "코코넛", "당근", "감자", "토마토", "양파", "마늘", "시금치", "상추",
    "오이", "피망", "호박", "브로콜리", "콜리플라워", "아스파라거스", "가지",
    "옥수수", "완두콩", "콩", "땅콩", "렌즈콩", "병아리콩", "쌀", "밀",
    "보리", "귀리", "콩", "두부", "세이탄", "퀴노아", "스파게티", "면", "파스타",
    "라면", "초밥", "타코", "부리또", "팔라펠", "후무스", "샤와르마", "피자", "파스타",
    "버거", "핫도그", "프렌치프라이", "양파링", "타터탯", "포테이토 웨지", "튀긴 치킨",
    "스테이크", "로스트 비프", "구운 치킨", "BBQ 립", "피시앤칩스", "라자냐", "카세롤",
    "파이", "케이크", "컵케이크", "머핀", "브라우니", "쿠키", "비스킷", "도넛",
    "크로와상", "베이글", "토스트", "팬케이크", "와플", "시리얼", "오트밀", "요거트",
    "치즈", "버터", "크림", "우유", "휘핑크림", "아이스크림", "셔벗", "냉동 요거트",
    "소르베", "젤라토", "초콜릿", "캔디", "껌", "팝콘", "칩", "프렛즐", "크래커",
    "치즈 퍼프", "과일 간식", "그래놀라", "트레일 믹스", "견과류", "피넛버터", "잼", "젤리",
    "꿀", "메이플 시럽", "식초", "간장", "핫소스", "머스터드", "케첩", "마요네즈",
    "샐러드 드레싱", "향신료", "소금", "후추", "마늘가루", "양파가루", "커민",
    "고수", "파프리카", "강황", "카레", "칠리파우더", "바질", "오레가노", "파슬리",
    "로즈마리", "타임", "세이지", "민트", "칠리 플레이크", "계피", "육두구",
    "정향", "카다몸", "올스파이스", "바닐라", "생강", "아몬드", "캐슈넛", "호두",
    "피스타치오", "헤이즐넛", "땅콩", "해바라기씨", "호박씨", "치아씨",
    "아마씨", "참깨", "코코넛 플레이크", "말린 과일", "건포도", "크랜베리",
    "블루베리", "살구", "망고", "파파야", "코코넛", "대추", "무화과", "카라멜",
    "마지팬", "푸딩", "젤리", "무스", "크림 퍼프", "에클레어", "티라미수", "치즈케이크",
    "바클라바", "커스터드", "츄로스", "도넛", "젤라토", "냉동 요거트", "소르베",
    "아이스크림", "선데", "스무디", "밀크셰이크", "주스", "물", "소다", "커피", "차", "맥주",
    "와인", "샴페인", "위스키", "보드카", "럼", "진", "테킬라", "브랜디", "코냑", "리큐르",
    "칵테일", "마티니", "마가리타", "모히토", "코스모폴리탄", "피나 콜라다", "블러디 메리",
    "진 토닉", "맥주", "라거", "필스너", "스타우트", "포터", "에일", "IPA", "밀맥주",
    "세종", "트라피스트 맥주", "사케", "소주", "보드카", "테킬라", "럼", "위스키", "버번",
    "스카치", "브랜디", "코냑", "리큐르", "앗센스", "메드", "칵테일", "맥주", "와인", "주류"
         };
    int dataset_size = sizeof(words) / sizeof(words[0]);
    for (int i = 0; i < dataset_size; i++) {
        strncpy(dictionary[current_size].word, words[i], MAX_WORD_SIZE - 1);
        strncpy(dictionary[current_size].meaning, meanings[i], MAX_MEANING_SIZE - 1);
        current_size++;
    }
}

// 사전 출력
void print_dictionary(element dict[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%s: %s\n", dict[i].word, dict[i].meaning);
    }
}

// 버블 정렬
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

// 삽입 정렬
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

// 퀵 정렬
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
   //printf("정렬 전 사전:\n");
    //print_dictionary(dictionary, current_size);

    // 버블 정렬
    start = clock();
    bubble_sort(dictionary, current_size);
    end = clock();
    printf("\n버블 정렬 소요 시간: %lf초\n", (double)(end - start) / CLOCKS_PER_SEC);

    // 정렬 후 출력
    //printf("\n정렬 후 사전:\n");
    //print_dictionary(dictionary, current_size);

    // 다른 정렬 알고리즘 성능 테스트
    generate_dataset(); // 초기화
    start = clock();
    insertion_sort(dictionary, current_size);
    end = clock();
    printf("\n삽입 정렬 소요 시간: %lf초\n", (double)(end - start) / CLOCKS_PER_SEC);

    generate_dataset(); // 초기화
    start = clock();
    quick_sort(dictionary, 0, current_size - 1);
    end = clock();
    printf("\n퀵 정렬 소요 시간: %lf초\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
