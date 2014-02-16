#ifndef INCLUDED_finda_Justinfront
#define INCLUDED_finda_Justinfront

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(finda,Justinfront)
HX_DECLARE_CLASS2(flash,display,Bitmap)
HX_DECLARE_CLASS2(flash,display,BitmapData)
HX_DECLARE_CLASS2(flash,display,DisplayObject)
HX_DECLARE_CLASS2(flash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(flash,events,EventDispatcher)
HX_DECLARE_CLASS2(flash,events,IEventDispatcher)
namespace finda{


class HXCPP_CLASS_ATTRIBUTES  Justinfront_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Justinfront_obj OBJ_;
		Justinfront_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Justinfront_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Justinfront_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Justinfront"); }

		static ::String name( Dynamic o);
		static Dynamic name_dyn();

		static ::flash::display::BitmapData copyToBitmapWithTransparency( ::flash::display::DisplayObject mc);
		static Dynamic copyToBitmapWithTransparency_dyn();

		static Void changeColor( ::flash::display::Bitmap bm,int col);
		static Dynamic changeColor_dyn();

};

} // end namespace finda

#endif /* INCLUDED_finda_Justinfront */ 
