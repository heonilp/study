package com.templatemethod;

public class ConcreteConnectHelper extends AbstConnectHelper {

	@Override
	protected String doSecurity(String info) {
		//강화된알고리즘 / 암호알고리즘 추가
		return info;
	}

	@Override
	protected String authentication(String id, String password) {
		//db에서 아이디 암호 확인과정 , 게임
		if(id.equals("abc")|password.equals("abc"))
			return "true info";
		else
			return "false info";
	}

	@Override
	protected int authorization(String userName) {
		//권한 확인, 셧다운 +@
		//서버에서 유저이름 유저나이를 알수있다.
		//나이를 확인하고 시간을 확인하고 성인이 아니고 10시면 ~end
		return 0;
	}

	@Override
	protected String connection(String info) {
		//마지막 접속단계, 필요한 정보들 넘김
		return info;
	}

}
