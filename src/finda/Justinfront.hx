package finda;
class Justinfront
{
    public static function name<T>( o: T ): String
    {
        var clazz = Type.getClass( o );
        return Type.getClassName( clazz );
    }
}