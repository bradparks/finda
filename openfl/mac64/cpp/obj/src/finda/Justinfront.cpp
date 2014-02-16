#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_finda_Justinfront
#include <finda/Justinfront.h>
#endif
#ifndef INCLUDED_flash_display_Bitmap
#include <flash/display/Bitmap.h>
#endif
#ifndef INCLUDED_flash_display_BitmapData
#include <flash/display/BitmapData.h>
#endif
#ifndef INCLUDED_flash_display_BlendMode
#include <flash/display/BlendMode.h>
#endif
#ifndef INCLUDED_flash_display_DisplayObject
#include <flash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_flash_display_IBitmapDrawable
#include <flash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_flash_events_EventDispatcher
#include <flash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_flash_events_IEventDispatcher
#include <flash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_flash_geom_ColorTransform
#include <flash/geom/ColorTransform.h>
#endif
#ifndef INCLUDED_flash_geom_Matrix
#include <flash/geom/Matrix.h>
#endif
#ifndef INCLUDED_flash_geom_Point
#include <flash/geom/Point.h>
#endif
#ifndef INCLUDED_flash_geom_Rectangle
#include <flash/geom/Rectangle.h>
#endif
#ifndef INCLUDED_flash_geom_Transform
#include <flash/geom/Transform.h>
#endif
namespace finda{

Void Justinfront_obj::__construct()
{
	return null();
}

Justinfront_obj::~Justinfront_obj() { }

Dynamic Justinfront_obj::__CreateEmpty() { return  new Justinfront_obj; }
hx::ObjectPtr< Justinfront_obj > Justinfront_obj::__new()
{  hx::ObjectPtr< Justinfront_obj > result = new Justinfront_obj();
	result->__construct();
	return result;}

Dynamic Justinfront_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Justinfront_obj > result = new Justinfront_obj();
	result->__construct();
	return result;}

::String Justinfront_obj::name( Dynamic o){
	HX_STACK_PUSH("Justinfront::name","finda/Justinfront.hx",15);
	HX_STACK_ARG(o,"o");
	HX_STACK_LINE(16)
	::Class clazz = ::Type_obj::getClass(o);		HX_STACK_VAR(clazz,"clazz");
	HX_STACK_LINE(17)
	return ::Type_obj::getClassName(clazz);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Justinfront_obj,name,return )

::flash::display::BitmapData Justinfront_obj::copyToBitmapWithTransparency( ::flash::display::DisplayObject mc){
	HX_STACK_PUSH("Justinfront::copyToBitmapWithTransparency","finda/Justinfront.hx",22);
	HX_STACK_ARG(mc,"mc");
	HX_STACK_LINE(24)
	int wide = ::Std_obj::_int(mc->get_width());		HX_STACK_VAR(wide,"wide");
	HX_STACK_LINE(25)
	int hi = ::Std_obj::_int(mc->get_height());		HX_STACK_VAR(hi,"hi");
	HX_STACK_LINE(27)
	::flash::geom::Point point = ::flash::geom::Point_obj::__new((int)0,(int)0);		HX_STACK_VAR(point,"point");
	HX_STACK_LINE(28)
	::flash::geom::Rectangle rect = ::flash::geom::Rectangle_obj::__new((int)0,(int)0,wide,hi);		HX_STACK_VAR(rect,"rect");
	HX_STACK_LINE(29)
	::flash::display::BitmapData abitmap = ::flash::display::BitmapData_obj::__new(wide,hi,true,(int)0,null());		HX_STACK_VAR(abitmap,"abitmap");
	HX_STACK_LINE(30)
	abitmap->draw(mc,null(),null(),null(),null(),null());
	HX_STACK_LINE(31)
	abitmap->copyPixels(abitmap,rect,point,abitmap,point,false);
	HX_STACK_LINE(32)
	return abitmap;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Justinfront_obj,copyToBitmapWithTransparency,return )

Void Justinfront_obj::changeColor( ::flash::display::Bitmap bm,int col){
{
		HX_STACK_PUSH("Justinfront::changeColor","finda/Justinfront.hx",37);
		HX_STACK_ARG(bm,"bm");
		HX_STACK_ARG(col,"col");
		HX_STACK_LINE(38)
		int red = (int(col) >> int((int)16));		HX_STACK_VAR(red,"red");
		HX_STACK_LINE(39)
		int green = (int((int(col) >> int((int)8))) & int((int)255));		HX_STACK_VAR(green,"green");
		HX_STACK_LINE(40)
		int blue = (int(col) & int((int)255));		HX_STACK_VAR(blue,"blue");
		HX_STACK_LINE(41)
		bm->get_transform()->set_colorTransform(::flash::geom::ColorTransform_obj::__new((int)0,(int)0,(int)0,(int)1,red,green,blue,(int)0));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Justinfront_obj,changeColor,(void))


Justinfront_obj::Justinfront_obj()
{
}

void Justinfront_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Justinfront);
	HX_MARK_END_CLASS();
}

void Justinfront_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Justinfront_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { return name_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"changeColor") ) { return changeColor_dyn(); }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"copyToBitmapWithTransparency") ) { return copyToBitmapWithTransparency_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Justinfront_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Justinfront_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("name"),
	HX_CSTRING("copyToBitmapWithTransparency"),
	HX_CSTRING("changeColor"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Justinfront_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Justinfront_obj::__mClass,"__mClass");
};

Class Justinfront_obj::__mClass;

void Justinfront_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("finda.Justinfront"), hx::TCanCast< Justinfront_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Justinfront_obj::__boot()
{
}

} // end namespace finda
