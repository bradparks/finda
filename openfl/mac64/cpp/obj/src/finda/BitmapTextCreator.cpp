#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_finda_BitmapTextCreator
#include <finda/BitmapTextCreator.h>
#endif
#ifndef INCLUDED_finda_Georgia
#include <finda/Georgia.h>
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
#ifndef INCLUDED_flash_display_InteractiveObject
#include <flash/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_flash_display_PixelSnapping
#include <flash/display/PixelSnapping.h>
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
#ifndef INCLUDED_flash_text_Font
#include <flash/text/Font.h>
#endif
#ifndef INCLUDED_flash_text_FontStyle
#include <flash/text/FontStyle.h>
#endif
#ifndef INCLUDED_flash_text_FontType
#include <flash/text/FontType.h>
#endif
#ifndef INCLUDED_flash_text_TextField
#include <flash/text/TextField.h>
#endif
#ifndef INCLUDED_flash_text_TextFieldAutoSize
#include <flash/text/TextFieldAutoSize.h>
#endif
#ifndef INCLUDED_flash_text_TextFormat
#include <flash/text/TextFormat.h>
#endif
namespace finda{

Void BitmapTextCreator_obj::__construct()
{
HX_STACK_PUSH("BitmapTextCreator::new","finda/BitmapTextCreator.hx",26);
{
	HX_STACK_LINE(27)
	this->font = ::finda::Georgia_obj::__new(null(),null(),null());
	HX_STACK_LINE(28)
	this->fmt = ::flash::text::TextFormat_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());
	HX_STACK_LINE(29)
	this->fmt->size = (int)23;
	HX_STACK_LINE(30)
	this->fmt->font = this->font->fontName;
	HX_STACK_LINE(31)
	this->fmt->color = (int)0;
	HX_STACK_LINE(32)
	this->tf = ::flash::text::TextField_obj::__new();
	HX_STACK_LINE(33)
	this->tf->set_embedFonts(true);
	HX_STACK_LINE(34)
	this->tf->set_defaultTextFormat(this->fmt);
	HX_STACK_LINE(35)
	this->tf->set_y((int)0);
	HX_STACK_LINE(36)
	this->tf->set_x((int)0);
	HX_STACK_LINE(37)
	this->tf->set_text(HX_CSTRING("BitmapTextCreator"));
	HX_STACK_LINE(38)
	this->tf->set_selectable(false);
	HX_STACK_LINE(39)
	this->tf->set_autoSize(::flash::text::TextFieldAutoSize_obj::LEFT);
}
;
	return null();
}

BitmapTextCreator_obj::~BitmapTextCreator_obj() { }

Dynamic BitmapTextCreator_obj::__CreateEmpty() { return  new BitmapTextCreator_obj; }
hx::ObjectPtr< BitmapTextCreator_obj > BitmapTextCreator_obj::__new()
{  hx::ObjectPtr< BitmapTextCreator_obj > result = new BitmapTextCreator_obj();
	result->__construct();
	return result;}

Dynamic BitmapTextCreator_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BitmapTextCreator_obj > result = new BitmapTextCreator_obj();
	result->__construct();
	return result;}

::flash::display::Bitmap BitmapTextCreator_obj::getBitmap( ::String str){
	HX_STACK_PUSH("BitmapTextCreator::getBitmap","finda/BitmapTextCreator.hx",45);
	HX_STACK_THIS(this);
	HX_STACK_ARG(str,"str");
	HX_STACK_LINE(46)
	this->tf->set_text(str);
	struct _Function_1_1{
		inline static ::flash::display::BitmapData Block( ::finda::BitmapTextCreator_obj *__this){
			HX_STACK_PUSH("*::closure","finda/BitmapTextCreator.hx",48);
			{
				HX_STACK_LINE(48)
				::flash::display::DisplayObject mc = __this->tf;		HX_STACK_VAR(mc,"mc");
				HX_STACK_LINE(48)
				int wide = ::Std_obj::_int(mc->get_width());		HX_STACK_VAR(wide,"wide");
				HX_STACK_LINE(48)
				int hi = ::Std_obj::_int(mc->get_height());		HX_STACK_VAR(hi,"hi");
				HX_STACK_LINE(48)
				::flash::geom::Point point = ::flash::geom::Point_obj::__new((int)0,(int)0);		HX_STACK_VAR(point,"point");
				HX_STACK_LINE(48)
				::flash::geom::Rectangle rect = ::flash::geom::Rectangle_obj::__new((int)0,(int)0,wide,hi);		HX_STACK_VAR(rect,"rect");
				HX_STACK_LINE(48)
				::flash::display::BitmapData abitmap = ::flash::display::BitmapData_obj::__new(wide,hi,true,(int)0,null());		HX_STACK_VAR(abitmap,"abitmap");
				HX_STACK_LINE(48)
				abitmap->draw(mc,null(),null(),null(),null(),null());
				HX_STACK_LINE(48)
				abitmap->copyPixels(abitmap,rect,point,abitmap,point,false);
				HX_STACK_LINE(48)
				return abitmap;
			}
			return null();
		}
	};
	HX_STACK_LINE(48)
	return ::flash::display::Bitmap_obj::__new(_Function_1_1::Block(this),null(),null());
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapTextCreator_obj,getBitmap,return )


BitmapTextCreator_obj::BitmapTextCreator_obj()
{
}

void BitmapTextCreator_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BitmapTextCreator);
	HX_MARK_MEMBER_NAME(tf,"tf");
	HX_MARK_MEMBER_NAME(fmt,"fmt");
	HX_MARK_MEMBER_NAME(font,"font");
	HX_MARK_END_CLASS();
}

void BitmapTextCreator_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(tf,"tf");
	HX_VISIT_MEMBER_NAME(fmt,"fmt");
	HX_VISIT_MEMBER_NAME(font,"font");
}

Dynamic BitmapTextCreator_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"tf") ) { return tf; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"fmt") ) { return fmt; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"font") ) { return font; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"getBitmap") ) { return getBitmap_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic BitmapTextCreator_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"tf") ) { tf=inValue.Cast< ::flash::text::TextField >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"fmt") ) { fmt=inValue.Cast< ::flash::text::TextFormat >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"font") ) { font=inValue.Cast< ::flash::text::Font >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void BitmapTextCreator_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("tf"));
	outFields->push(HX_CSTRING("fmt"));
	outFields->push(HX_CSTRING("font"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getBitmap"),
	HX_CSTRING("tf"),
	HX_CSTRING("fmt"),
	HX_CSTRING("font"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BitmapTextCreator_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BitmapTextCreator_obj::__mClass,"__mClass");
};

Class BitmapTextCreator_obj::__mClass;

void BitmapTextCreator_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("finda.BitmapTextCreator"), hx::TCanCast< BitmapTextCreator_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void BitmapTextCreator_obj::__boot()
{
}

} // end namespace finda
