package com.templatemethod;

public abstract class AbstConnectHelper {
	//여러단계로 나눈다
	//단계를 메소드로 선언한다.
	// protected : 하위 클래스 재정의를 위해서 선언
	abstract protected String doSecurity(String info);

	abstract protected String authentication(String id, String password);

	abstract protected int authorization(String userName);

	abstract protected String connection(String info);
	//템플릿메소드를 만든다
	public String requestConnection(String info) {

		String id, password, userName, decodedInfo, userInfo;

		//하위클래스에서 나눠진 메소드를 구현한다.
		// 암호화된 정보를 복호화 합니다.
		decodedInfo = doSecurity(info);

		// decodedInfo에서 id 와 password를 추출
		id = "abc";
		password = "abc";
         //하위클래스에서 나눠진 메소드를 구현한다.
		userInfo = authentication(id, password);

		// userInfo에서 userName을 찾아 냅니다.
		userName = "abc";
       //하위클래스에서 나눠진 메소드를 구현한다.
		int result = authorization(userName);

		switch (result) {

		case 0:// 무료회원
			break;
		case 1:// 유료회원
			break;
		case 2:// 게임 마스터
			break;
		case 3:// 접속 권한 없음
			break;
		default:
			break;
		}
        //하위클래스에서 나눠진 메소드를 구현한다.
		return connection(userInfo);
	}
}
