package haxe.root;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Array_iterator_381__Fun<T> extends haxe.lang.Function
{
	public    Array_iterator_381__Fun(haxe.root.Array<java.lang.Object> i, haxe.root.Array<haxe.root.Array> _g)
	{
		super(0, 0);
		this.i = i;
		this._g = _g;
	}
	
	
	@Override public   java.lang.Object __hx_invoke0_o()
	{
		T[] __temp_stmt30 = ((haxe.root.Array<T>) (((haxe.root.Array) (this._g.__get(0)) )) ).__a;
		int __temp_stmt31 = 0;
		{
			int __temp_arrIndex20 = 0;
			int __temp_arrVal18 = ((int) (haxe.lang.Runtime.toInt(this.i.__get(__temp_arrIndex20))) );
			int __temp_arrRet19 = __temp_arrVal18++;
			int __temp_expr32 = ((int) (haxe.lang.Runtime.toInt(this.i.__set(__temp_arrIndex20, __temp_arrVal18))) );
			__temp_stmt31 = __temp_arrRet19;
		}
		
		return __temp_stmt30[__temp_stmt31];
	}
	
	
	public  haxe.root.Array<java.lang.Object> i;
	
	public  haxe.root.Array<haxe.root.Array> _g;
	
}


