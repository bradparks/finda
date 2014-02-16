#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_finda_BitmapTextCreator
#include <finda/BitmapTextCreator.h>
#endif
#ifndef INCLUDED_finda_FileViewCreatorFL
#include <finda/FileViewCreatorFL.h>
#endif
#ifndef INCLUDED_flash_display_Bitmap
#include <flash/display/Bitmap.h>
#endif
#ifndef INCLUDED_flash_display_DisplayObject
#include <flash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_flash_display_DisplayObjectContainer
#include <flash/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_flash_display_IBitmapDrawable
#include <flash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_flash_display_InteractiveObject
#include <flash/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_flash_display_Sprite
#include <flash/display/Sprite.h>
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
#ifndef INCLUDED_flash_geom_Transform
#include <flash/geom/Transform.h>
#endif
namespace finda{

Void FileViewCreatorFL_obj::__construct(::flash::display::Sprite g2D,int x_)
{
HX_STACK_PUSH("FileViewCreatorFL::new","finda/FileViewCreatorFL.hx",12);
{
	HX_STACK_LINE(13)
	this->x = x_;
	HX_STACK_LINE(14)
	this->bitmapTextCreator = ::finda::BitmapTextCreator_obj::__new();
}
;
	return null();
}

FileViewCreatorFL_obj::~FileViewCreatorFL_obj() { }

Dynamic FileViewCreatorFL_obj::__CreateEmpty() { return  new FileViewCreatorFL_obj; }
hx::ObjectPtr< FileViewCreatorFL_obj > FileViewCreatorFL_obj::__new(::flash::display::Sprite g2D,int x_)
{  hx::ObjectPtr< FileViewCreatorFL_obj > result = new FileViewCreatorFL_obj();
	result->__construct(g2D,x_);
	return result;}

Dynamic FileViewCreatorFL_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FileViewCreatorFL_obj > result = new FileViewCreatorFL_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Dynamic FileViewCreatorFL_obj::create( ::flash::display::Sprite g2D,Dynamic file,::String tx,int h,int c){
	HX_STACK_PUSH("FileViewCreatorFL::create","finda/FileViewCreatorFL.hx",22);
	HX_STACK_THIS(this);
	HX_STACK_ARG(g2D,"g2D");
	HX_STACK_ARG(file,"file");
	HX_STACK_ARG(tx,"tx");
	HX_STACK_ARG(h,"h");
	HX_STACK_ARG(c,"c");
	HX_STACK_LINE(23)
	::flash::display::Bitmap shape = this->bitmapTextCreator->getBitmap(tx);		HX_STACK_VAR(shape,"shape");
	HX_STACK_LINE(24)
	int wide = ::Std_obj::_int(shape->get_width());		HX_STACK_VAR(wide,"wide");
	HX_STACK_LINE(25)
	int hi = ::Std_obj::_int(shape->get_height());		HX_STACK_VAR(hi,"hi");
	HX_STACK_LINE(26)
	int xpos = this->x;		HX_STACK_VAR(xpos,"xpos");
	HX_STACK_LINE(27)
	int ypos = hx::AddEq(h,hi);		HX_STACK_VAR(ypos,"ypos");
	HX_STACK_LINE(28)
	{
		HX_STACK_LINE(28)
		int red = (int(c) >> int((int)16));		HX_STACK_VAR(red,"red");
		HX_STACK_LINE(28)
		int green = (int((int(c) >> int((int)8))) & int((int)255));		HX_STACK_VAR(green,"green");
		HX_STACK_LINE(28)
		int blue = (int(c) & int((int)255));		HX_STACK_VAR(blue,"blue");
		HX_STACK_LINE(28)
		shape->get_transform()->set_colorTransform(::flash::geom::ColorTransform_obj::__new((int)0,(int)0,(int)0,(int)1,red,green,blue,(int)0));
	}
	struct _Function_1_1{
		inline static Dynamic Block( int &c,int &wide,::flash::display::Bitmap &shape,int &hi,int &xpos,Dynamic &file,int &ypos){
			HX_STACK_PUSH("*::closure","finda/FileViewCreatorFL.hx",30);
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("file") , file,false);
				__result->Add(HX_CSTRING("shape") , shape,false);
				__result->Add(HX_CSTRING("change") , false,false);
				__result->Add(HX_CSTRING("color") , c,false);
				__result->Add(HX_CSTRING("x") , xpos,false);
				__result->Add(HX_CSTRING("y") , ypos,false);
				__result->Add(HX_CSTRING("width") , wide,false);
				__result->Add(HX_CSTRING("height") , hi,false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(30)
	Dynamic fileView = _Function_1_1::Block(c,wide,shape,hi,xpos,file,ypos);		HX_STACK_VAR(fileView,"fileView");
	HX_STACK_LINE(40)
	return fileView;
}


HX_DEFINE_DYNAMIC_FUNC5(FileViewCreatorFL_obj,create,return )


FileViewCreatorFL_obj::FileViewCreatorFL_obj()
{
}

void FileViewCreatorFL_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FileViewCreatorFL);
	HX_MARK_MEMBER_NAME(x,"x");
	HX_MARK_MEMBER_NAME(bitmapTextCreator,"bitmapTextCreator");
	HX_MARK_END_CLASS();
}

void FileViewCreatorFL_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(x,"x");
	HX_VISIT_MEMBER_NAME(bitmapTextCreator,"bitmapTextCreator");
}

Dynamic FileViewCreatorFL_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { return x; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"create") ) { return create_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"bitmapTextCreator") ) { return bitmapTextCreator; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FileViewCreatorFL_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { x=inValue.Cast< int >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"bitmapTextCreator") ) { bitmapTextCreator=inValue.Cast< ::finda::BitmapTextCreator >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FileViewCreatorFL_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("x"));
	outFields->push(HX_CSTRING("bitmapTextCreator"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("create"),
	HX_CSTRING("x"),
	HX_CSTRING("bitmapTextCreator"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FileViewCreatorFL_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FileViewCreatorFL_obj::__mClass,"__mClass");
};

Class FileViewCreatorFL_obj::__mClass;

void FileViewCreatorFL_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("finda.FileViewCreatorFL"), hx::TCanCast< FileViewCreatorFL_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void FileViewCreatorFL_obj::__boot()
{
}

} // end namespace finda
