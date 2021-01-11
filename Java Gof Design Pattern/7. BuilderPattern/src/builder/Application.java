package builder;

public class Application {

	//1
	///복잡한 단계가 필요한 인스턴스 생얼을 빌러 패턴을 통해 구현할수 있다.
	// 객체들을 빌더들한테 넘김, 시공자같은 느낌
	//빌더 패턴 : 복잡한 단계를 거쳐야 생성되는 객체의 구현을 서브 클래스에게 넘겨주는 패턴

	//2
	//많은 변수를 가진 객체의 생성을 가독성 높도록 코딩할수 있다.
	//가독성 & 많은 멤버 변수가 많을때...
	//빌더패턴 많은 인자를 가진 객체를 생성을 다른 객체의 도움으로 생성하는 패턴

	 public static void main(String[] args) {
		MonsterDirector director = new MonsterDirector();
		
		Builder builder = new ATypeMonsterBuilder();

		director.setBuilder(builder);
		
		System.out.println(director.gen());

		builder = new BTypeMonsterBuilder();
		director.setBuilder(builder);
		Monster monster = director.gen();
		
		System.out.println(monster);
	}
}

//빌더패턴 참고
//https://johngrib.github.io/wiki/builder-pattern/


// Effective Java의 Builder Pattern
/*
public class NutritionFacts {
	private final int servingSize;
	private final int servings;
	private final int calories;
	private final int fat;
	private final int sodium;
	private final int carbohydrate;

	public static class Builder {
		// Required parameters(필수 인자)
		private final int servingSize;
		private final int servings;

		// Optional parameters - initialized to default values(선택적 인자는 기본값으로 초기화)
		private int calories      = 0;
		private int fat           = 0;
		private int carbohydrate  = 0;
		private int sodium        = 0;

		public Builder(int servingSize, int servings) {
			this.servingSize = servingSize;
			this.servings    = servings;
		}

		public Builder calories(int val) {
			calories = val;
			return this;    // 이렇게 하면 . 으로 체인을 이어갈 수 있다.
		}
		public Builder fat(int val) {
			fat = val;
			return this;
		}
		public Builder carbohydrate(int val) {
			carbohydrate = val;
			return this;
		}
		public Builder sodium(int val) {
			sodium = val;
			return this;
		}
		public NutritionFacts build() {
			return new NutritionFacts(this);
		}
	}

	private NutritionFacts(Builder builder) {
		servingSize  = builder.servingSize;
		servings     = builder.servings;
		calories     = builder.calories;
		fat          = builder.fat;
		sodium       = builder.sodium;
		carbohydrate = builder.carbohydrate;
	}
}
// 각 줄마다 builder를 타이핑하지 않아도 되어 편리하다.
NutritionFacts cocaCola = new NutritionFacts
    .Builder(240, 8)    // 필수값 입력
    .calories(100)
    .sodium(35)
    .carbohydrate(27)
    .build();           // build() 가 객체를 생성해 돌려준다.


각 인자가 어떤 의미인지 알기 쉽다.
setter 메소드가 없으므로 변경 불가능 객체를 만들 수 있다.
한 번에 객체를 생성하므로 객체 일관성이 깨지지 않는다.
build() 함수가 잘못된 값이 입력되었는지 검증하게 할 수도 있다.

*/