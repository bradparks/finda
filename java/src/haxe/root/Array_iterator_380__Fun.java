package haxe.root;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Array_iterator_380__Fun extends haxe.lang.Function
{
	public    Array_iterator_380__Fun(haxe.root.Array<java.lang.Object> i, haxe.root.Array<java.lang.Object> len)
	{
		super(0, 0);
		this.i = i;
		this.len = len;
	}
	
	
	@Override public   java.lang.Object __hx_invoke0_o()
	{
		return ( ((int) (haxe.lang.Runtime.toInt(this.i.__get(0))) ) < ((int) (haxe.lang.Runtime.toInt(this.len.__get(0))) ) );
	}
	
	
	public  haxe.root.Array<java.lang.Object> i;
	
	public  haxe.root.Array<java.lang.Object> len;
	
}


