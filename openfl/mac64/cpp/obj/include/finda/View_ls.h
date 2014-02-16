#ifndef INCLUDED_finda_View_ls
#define INCLUDED_finda_View_ls

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(finda,PathInfo)
HX_DECLARE_CLASS1(finda,View_ls)
HX_DECLARE_CLASS2(flash,display,DisplayObject)
HX_DECLARE_CLASS2(flash,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(flash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(flash,display,InteractiveObject)
HX_DECLARE_CLASS2(flash,display,Sprite)
HX_DECLARE_CLASS2(flash,events,Event)
HX_DECLARE_CLASS2(flash,events,EventDispatcher)
HX_DECLARE_CLASS2(flash,events,IEventDispatcher)
HX_DECLARE_CLASS2(flash,events,MouseEvent)
namespace finda{


class HXCPP_CLASS_ATTRIBUTES  View_ls_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef View_ls_obj OBJ_;
		View_ls_obj();
		Void __construct(::finda::PathInfo pathInfo_,int x_,int y_);

	public:
		static hx::ObjectPtr< View_ls_obj > __new(::finda::PathInfo pathInfo_,int x_,int y_);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~View_ls_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("View_ls"); }

		virtual Dynamic overCheck( ::flash::events::MouseEvent e);
		Dynamic overCheck_dyn();

		virtual Void clicked( Dynamic f);
		Dynamic clicked_dyn();

		virtual Void secondPaint( ::flash::display::Sprite g2D);
		Dynamic secondPaint_dyn();

		virtual Void firstPaint( ::flash::display::Sprite g2D);
		Dynamic firstPaint_dyn();

		virtual Void change( );
		Dynamic change_dyn();

		Dynamic shapes;
		Dynamic repaint;
		Dynamic &repaint_dyn() { return repaint;}
		::finda::PathInfo pathInfo;
		int y;
		int x;
};

} // end namespace finda

#endif /* INCLUDED_finda_View_ls */ 
