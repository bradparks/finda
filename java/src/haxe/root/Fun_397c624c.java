package haxe.root;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Fun_397c624c<T> extends haxe.lang.Function
{
	public    Fun_397c624c(haxe.root.Array<java.lang.Object> i, haxe.root.Array<haxe.root.Array> _g)
	{
		super(0, 0);
		this.i = i;
		this._g = _g;
	}
	
	
	@Override public   java.lang.Object __hx_invoke0_o()
	{
		T[] __temp_stmt34 = ((haxe.root.Array<T>) (((haxe.root.Array) (this._g.__get(0)) )) ).__a;
		int __temp_stmt35 = 0;
		{
			int __temp_arrIndex23 = 0;
			int __temp_arrVal21 = ((int) (haxe.lang.Runtime.toInt(this.i.__get(__temp_arrIndex23))) );
			int __temp_arrRet22 = __temp_arrVal21++;
			int __temp_expr36 = ((int) (haxe.lang.Runtime.toInt(this.i.__set(__temp_arrIndex23, __temp_arrVal21))) );
			__temp_stmt35 = __temp_arrRet22;
		}
		
		return __temp_stmt34[__temp_stmt35];
	}
	
	
	public  haxe.root.Array<java.lang.Object> i;
	
	public  haxe.root.Array<haxe.root.Array> _g;
	
}


