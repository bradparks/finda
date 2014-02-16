#ifndef INCLUDED_finda_MainOpenfl
#define INCLUDED_finda_MainOpenfl

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <flash/display/Sprite.h>
HX_DECLARE_CLASS1(finda,MainOpenfl)
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


class HXCPP_CLASS_ATTRIBUTES  MainOpenfl_obj : public ::flash::display::Sprite_obj{
	public:
		typedef ::flash::display::Sprite_obj super;
		typedef MainOpenfl_obj OBJ_;
		MainOpenfl_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< MainOpenfl_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~MainOpenfl_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("MainOpenfl"); }

		virtual Void mouseReleased( ::flash::events::MouseEvent e);
		Dynamic mouseReleased_dyn();

		virtual Void mouseClicked( ::flash::events::MouseEvent e);
		Dynamic mouseClicked_dyn();

		virtual Void mouseDragged( ::flash::events::MouseEvent e);
		Dynamic mouseDragged_dyn();

		virtual Void mousePressed( ::flash::events::MouseEvent e);
		Dynamic mousePressed_dyn();

		virtual Void overCheck( ::flash::events::MouseEvent e);
		Dynamic overCheck_dyn();

		virtual Void mouseMoved( ::flash::events::MouseEvent e);
		Dynamic mouseMoved_dyn();

		virtual Void repaint( );
		Dynamic repaint_dyn();

		virtual Void setupListeners( );
		Dynamic setupListeners_dyn();

		int boundary;
		bool down;
		int dy;
		int dx;
		::finda::PathInfo pathI;
		::finda::View_ls view;
		Dynamic fileView;
		::finda::PathInfo pathInfo2;
		::finda::PathInfo pathInfo;
		::finda::View_ls view_ls2;
		::finda::View_ls view_ls;
		::flash::display::Sprite sp;
};

} // end namespace finda

#endif /* INCLUDED_finda_MainOpenfl */ 
