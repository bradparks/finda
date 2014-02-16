#ifndef INCLUDED_finda_BitmapTextCreator
#define INCLUDED_finda_BitmapTextCreator

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(finda,BitmapTextCreator)
HX_DECLARE_CLASS2(flash,display,Bitmap)
HX_DECLARE_CLASS2(flash,display,DisplayObject)
HX_DECLARE_CLASS2(flash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(flash,display,InteractiveObject)
HX_DECLARE_CLASS2(flash,events,EventDispatcher)
HX_DECLARE_CLASS2(flash,events,IEventDispatcher)
HX_DECLARE_CLASS2(flash,text,Font)
HX_DECLARE_CLASS2(flash,text,TextField)
HX_DECLARE_CLASS2(flash,text,TextFormat)
namespace finda{


class HXCPP_CLASS_ATTRIBUTES  BitmapTextCreator_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef BitmapTextCreator_obj OBJ_;
		BitmapTextCreator_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< BitmapTextCreator_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BitmapTextCreator_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("BitmapTextCreator"); }

		virtual ::flash::display::Bitmap getBitmap( ::String str);
		Dynamic getBitmap_dyn();

		::flash::text::TextField tf;
		::flash::text::TextFormat fmt;
		::flash::text::Font font;
};

} // end namespace finda

#endif /* INCLUDED_finda_BitmapTextCreator */ 
