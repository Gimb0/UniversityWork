class A {
    int i = 0;
    private void f() {
        i = 1;
    };
    void g() {
        i = 11;
    };
    A() {
        f();
    }
    A(boolean x) {
        g();
    }
}

class B extends A {
    void f() {
        i = 9;
    };
    public void g() {
        i = 99;
    };
    public int h() {
        return i;
    }
    B() {
        super();
    }
    B(boolean x) {
        super(x);
    }
    public static void main(String[] args) {
        System.out.println(new B().h());
        System.out.println(new B(true).h());
    }
}
