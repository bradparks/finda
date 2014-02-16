#include <hxcpp.h>

#ifndef INCLUDED_finda_Georgia
#include <finda/Georgia.h>
#endif
#ifndef INCLUDED_flash_text_Font
#include <flash/text/Font.h>
#endif
#ifndef INCLUDED_flash_text_FontStyle
#include <flash/text/FontStyle.h>
#endif
#ifndef INCLUDED_flash_text_FontType
#include <flash/text/FontType.h>
#endif
namespace finda{

Void Georgia_obj::__construct(::String __o_filename,::flash::text::FontStyle style,::flash::text::FontType type)
{
HX_STACK_PUSH("Georgia::new","finda/BitmapTextCreator.hx",16);
::String filename = __o_filename.Default(HX_CSTRING(""));
{
	HX_STACK_LINE(16)
	super::__construct(filename,style,type);
}
;
	return null();
}

Georgia_obj::~Georgia_obj() { }

Dynamic Georgia_obj::__CreateEmpty() { return  new Georgia_obj; }
hx::ObjectPtr< Georgia_obj > Georgia_obj::__new(::String __o_filename,::flash::text::FontStyle style,::flash::text::FontType type)
{  hx::ObjectPtr< Georgia_obj > result = new Georgia_obj();
	result->__construct(__o_filename,style,type);
	return result;}

Dynamic Georgia_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Georgia_obj > result = new Georgia_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

::String Georgia_obj::resourceName;


Georgia_obj::Georgia_obj()
{
}

void Georgia_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Georgia);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Georgia_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Georgia_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"resourceName") ) { return resourceName; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Georgia_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"resourceName") ) { resourceName=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Georgia_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("resourceName"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Georgia_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Georgia_obj::resourceName,"resourceName");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Georgia_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Georgia_obj::resourceName,"resourceName");
};

Class Georgia_obj::__mClass;

void Georgia_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("finda.Georgia"), hx::TCanCast< Georgia_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Georgia_obj::__boot()
{
	resourceName= HX_CSTRING("NME_font_finda_Georgia");
}

} // end namespace finda
