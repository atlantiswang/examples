/*
 *	单例模式是解决全局对象的创建的问题， 工厂模式是解决局部对象的创建问题
	工厂模式其实就是把有相同基类的对象的创建放入一个工厂类的方法中完成(简单工厂模式)。
	为什么要放到工厂中完成？
	要创建的类的名字太多时方便。
	工厂类也可以做成抽象的一个类（把创建的过程延迟到子类中）(工厂方法模式，抽象的类，一般有很多子类，让不同的子类做为创建不同对象的选择)。
	当创建的对象也不止一个抽象类时，就变成了抽象工厂方法（创建一组类）。
	node: 一个类为抽象类时，他的子类一般是广度继承的，而不是深度继承的，因为深度继续的模型一般是用于子类用于丰富父类的模型。而广度继承而
	适应于接口方法都一致，通过子类的不同来区分不同的实例。
 */
