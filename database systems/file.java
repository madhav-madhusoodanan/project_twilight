class File {
	public static void main(String[] args){
		String str = "abc";
		MyMethod(str);
		System.out.println(str);
	}
	public static void MyMethod(String str){
		str = "def";
		System.out.println(str);
	}
}
