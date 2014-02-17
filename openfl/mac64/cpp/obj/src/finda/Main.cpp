#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_finda_Main
#include <finda/Main.h>
#endif
#ifndef INCLUDED_finda_PathInfo
#include <finda/PathInfo.h>
#endif
#ifndef INCLUDED_finda_View_ls
#include <finda/View_ls.h>
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
#ifndef INCLUDED_flash_events_Event
#include <flash/events/Event.h>
#endif
#ifndef INCLUDED_flash_events_EventDispatcher
#include <flash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_flash_events_IEventDispatcher
#include <flash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_flash_events_MouseEvent
#include <flash/events/MouseEvent.h>
#endif
#ifndef INCLUDED_sys_FileSystem
#include <sys/FileSystem.h>
#endif
namespace finda{

Void Main_obj::__construct()
{
HX_STACK_PUSH("Main::new","finda/Main.hx",24);
{
	HX_STACK_LINE(53)
	this->boundary = (int)250;
	HX_STACK_LINE(52)
	this->down = false;
	HX_STACK_LINE(69)
	super::__construct();
	HX_STACK_LINE(71)
	this->sp = ::flash::display::Sprite_obj::__new();
	HX_STACK_LINE(72)
	this->addChild(this->sp);
	HX_STACK_LINE(75)
	this->createViews();
	HX_STACK_LINE(79)
	this->repaint();
	HX_STACK_LINE(81)
	this->setupListeners();
}
;
	return null();
}

Main_obj::~Main_obj() { }

Dynamic Main_obj::__CreateEmpty() { return  new Main_obj; }
hx::ObjectPtr< Main_obj > Main_obj::__new()
{  hx::ObjectPtr< Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

Dynamic Main_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

Void Main_obj::mouseReleased( ::flash::events::MouseEvent e){
{
		HX_STACK_PUSH("Main::mouseReleased","finda/Main.hx",241);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(242)
		this->down = false;
		HX_STACK_LINE(245)
		if (((bool((this->fileView->__Field(HX_CSTRING("x"),true) < this->boundary)) && bool((this->view == this->view_ls2))))){
			HX_STACK_LINE(246)
			::sys::FileSystem_obj::rename(((this->pathI->path + HX_CSTRING("/")) + this->fileView->__Field(HX_CSTRING("file"),true)->__Field(HX_CSTRING("name"),true)),((this->pathInfo->path + HX_CSTRING("/")) + this->fileView->__Field(HX_CSTRING("file"),true)->__Field(HX_CSTRING("name"),true)));
			HX_STACK_LINE(248)
			this->pathI->changePath(this->pathInfo->path);
			HX_STACK_LINE(249)
			this->pathI->changePath(this->pathInfo2->path);
			HX_STACK_LINE(250)
			this->view_ls->change();
			HX_STACK_LINE(251)
			this->view_ls2->change();
			HX_STACK_LINE(256)
			this->repaint();
		}
		else{
			HX_STACK_LINE(259)
			if (((bool((this->fileView->__Field(HX_CSTRING("x"),true) > this->boundary)) && bool((this->view == this->view_ls))))){
				HX_STACK_LINE(260)
				::sys::FileSystem_obj::rename(((this->pathI->path + HX_CSTRING("/")) + this->fileView->__Field(HX_CSTRING("file"),true)->__Field(HX_CSTRING("name"),true)),((this->pathInfo2->path + HX_CSTRING("/")) + this->fileView->__Field(HX_CSTRING("file"),true)->__Field(HX_CSTRING("name"),true)));
				HX_STACK_LINE(262)
				this->pathI->changePath(this->pathInfo->path);
				HX_STACK_LINE(263)
				this->pathI->changePath(this->pathInfo2->path);
				HX_STACK_LINE(264)
				this->view_ls->change();
				HX_STACK_LINE(265)
				this->view_ls2->change();
				HX_STACK_LINE(270)
				this->repaint();
			}
			else{
				HX_STACK_LINE(275)
				this->view_ls->change();
				HX_STACK_LINE(276)
				this->view_ls2->change();
				HX_STACK_LINE(281)
				this->repaint();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,mouseReleased,(void))

Void Main_obj::mouseClicked( ::flash::events::MouseEvent e){
{
		HX_STACK_PUSH("Main::mouseClicked","finda/Main.hx",228);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(228)
		if (((this->fileView != null()))){
			HX_STACK_LINE(230)
			this->view->clicked(this->fileView);
			HX_STACK_LINE(234)
			this->repaint();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,mouseClicked,(void))

Void Main_obj::mouseDragged( ::flash::events::MouseEvent e){
{
		HX_STACK_PUSH("Main::mouseDragged","finda/Main.hx",217);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(219)
		this->fileView->__FieldRef(HX_CSTRING("x")) = ::Std_obj::_int((e->localX - this->dx));
		HX_STACK_LINE(220)
		this->fileView->__FieldRef(HX_CSTRING("y")) = ::Std_obj::_int((e->localY - this->dy));
		HX_STACK_LINE(221)
		this->fileView->__FieldRef(HX_CSTRING("change")) = true;
		HX_STACK_LINE(223)
		this->repaint();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,mouseDragged,(void))

Void Main_obj::mousePressed( ::flash::events::MouseEvent e){
{
		HX_STACK_PUSH("Main::mousePressed","finda/Main.hx",190);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		struct _Function_1_1{
			inline static Dynamic Block( ::flash::events::MouseEvent &e){
				HX_STACK_PUSH("*::closure","finda/Main.hx",194);
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("x") , e->localX,false);
					__result->Add(HX_CSTRING("y") , e->localY,false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(194)
		Dynamic point = _Function_1_1::Block(e);		HX_STACK_VAR(point,"point");
		HX_STACK_LINE(196)
		if (((this->fileView != null()))){
			HX_STACK_LINE(198)
			this->dx = ::Std_obj::_int((point->__Field(HX_CSTRING("x"),true) - this->fileView->__Field(HX_CSTRING("x"),true)));
			HX_STACK_LINE(199)
			this->dy = ::Std_obj::_int((point->__Field(HX_CSTRING("y"),true) - this->fileView->__Field(HX_CSTRING("y"),true)));
			HX_STACK_LINE(200)
			this->down = true;
		}
		else{
			HX_STACK_LINE(201)
			this->down = false;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,mousePressed,(void))

Void Main_obj::overCheck( ::flash::events::MouseEvent e){
{
		HX_STACK_PUSH("Main::overCheck","finda/Main.hx",151);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(152)
		Dynamic fileView1 = this->view_ls->overCheck(e);		HX_STACK_VAR(fileView1,"fileView1");
		HX_STACK_LINE(153)
		Dynamic fileView2 = this->view_ls2->overCheck(e);		HX_STACK_VAR(fileView2,"fileView2");
		HX_STACK_LINE(154)
		bool bool1 = (fileView1 != null());		HX_STACK_VAR(bool1,"bool1");
		HX_STACK_LINE(155)
		bool bool2 = (fileView2 != null());		HX_STACK_VAR(bool2,"bool2");
		HX_STACK_LINE(156)
		if (((bool(bool1) || bool(bool2)))){
			HX_STACK_LINE(163)
			this->sp->useHandCursor = true;
			HX_STACK_LINE(166)
			if ((bool1)){
				HX_STACK_LINE(167)
				this->fileView = fileView1;
				HX_STACK_LINE(168)
				this->pathI = this->pathInfo;
				HX_STACK_LINE(169)
				this->view = this->view_ls;
			}
			else{
				HX_STACK_LINE(170)
				if ((bool2)){
					HX_STACK_LINE(171)
					this->fileView = fileView2;
					HX_STACK_LINE(172)
					this->pathI = this->pathInfo2;
					HX_STACK_LINE(173)
					this->view = this->view_ls2;
				}
			}
		}
		else{
			HX_STACK_LINE(181)
			this->sp->useHandCursor = false;
			HX_STACK_LINE(183)
			this->fileView = null();
		}
		HX_STACK_LINE(186)
		if ((this->down)){
			HX_STACK_LINE(186)
			this->mouseDragged(e);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,overCheck,(void))

Void Main_obj::mouseMoved( ::flash::events::MouseEvent e){
{
		HX_STACK_PUSH("Main::mouseMoved","finda/Main.hx",150);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(150)
		this->overCheck(e);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,mouseMoved,(void))

Void Main_obj::repaint( ){
{
		HX_STACK_PUSH("Main::repaint","finda/Main.hx",143);
		HX_STACK_THIS(this);
		HX_STACK_LINE(144)
		while(((this->sp->get_numChildren() > (int)0))){
			HX_STACK_LINE(144)
			this->sp->removeChildAt((int)0);
		}
		HX_STACK_LINE(145)
		this->view_ls->repaint(this->sp);
		HX_STACK_LINE(146)
		this->view_ls2->repaint(this->sp);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,repaint,(void))

Void Main_obj::setupListeners( ){
{
		HX_STACK_PUSH("Main::setupListeners","finda/Main.hx",125);
		HX_STACK_THIS(this);
		HX_STACK_LINE(126)
		this->sp->buttonMode = true;
		HX_STACK_LINE(127)
		this->sp->set_mouseChildren(false);
		HX_STACK_LINE(128)
		this->sp->useHandCursor = true;
		HX_STACK_LINE(129)
		this->sp->addEventListener(::flash::events::MouseEvent_obj::MOUSE_MOVE,this->mouseMoved_dyn(),null(),null(),null());
		HX_STACK_LINE(130)
		this->sp->addEventListener(::flash::events::MouseEvent_obj::MOUSE_DOWN,this->mousePressed_dyn(),null(),null(),null());
		HX_STACK_LINE(131)
		this->sp->addEventListener(::flash::events::MouseEvent_obj::MOUSE_UP,this->mouseReleased_dyn(),null(),null(),null());
		HX_STACK_LINE(132)
		this->sp->addEventListener(::flash::events::MouseEvent_obj::CLICK,this->mouseClicked_dyn(),null(),null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,setupListeners,(void))

Void Main_obj::createViews( ){
{
		HX_STACK_PUSH("Main::createViews","finda/Main.hx",99);
		HX_STACK_THIS(this);
		HX_STACK_LINE(102)
		::String offsetDir = HX_CSTRING("../../../../../../");		HX_STACK_VAR(offsetDir,"offsetDir");
		HX_STACK_LINE(107)
		this->pathInfo = ::finda::PathInfo_obj::__new((offsetDir + HX_CSTRING("./")));
		HX_STACK_LINE(108)
		this->pathInfo2 = ::finda::PathInfo_obj::__new((offsetDir + HX_CSTRING("../")));
		HX_STACK_LINE(110)
		this->view_ls = ::finda::View_ls_obj::__new(this->pathInfo,(int)25,(int)25);
		HX_STACK_LINE(111)
		this->view_ls2 = ::finda::View_ls_obj::__new(this->pathInfo2,(int)300,(int)25);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,createViews,(void))


Main_obj::Main_obj()
{
}

void Main_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Main);
	HX_MARK_MEMBER_NAME(boundary,"boundary");
	HX_MARK_MEMBER_NAME(down,"down");
	HX_MARK_MEMBER_NAME(dy,"dy");
	HX_MARK_MEMBER_NAME(dx,"dx");
	HX_MARK_MEMBER_NAME(pathI,"pathI");
	HX_MARK_MEMBER_NAME(view,"view");
	HX_MARK_MEMBER_NAME(fileView,"fileView");
	HX_MARK_MEMBER_NAME(pathInfo2,"pathInfo2");
	HX_MARK_MEMBER_NAME(pathInfo,"pathInfo");
	HX_MARK_MEMBER_NAME(view_ls2,"view_ls2");
	HX_MARK_MEMBER_NAME(view_ls,"view_ls");
	HX_MARK_MEMBER_NAME(sp,"sp");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Main_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(boundary,"boundary");
	HX_VISIT_MEMBER_NAME(down,"down");
	HX_VISIT_MEMBER_NAME(dy,"dy");
	HX_VISIT_MEMBER_NAME(dx,"dx");
	HX_VISIT_MEMBER_NAME(pathI,"pathI");
	HX_VISIT_MEMBER_NAME(view,"view");
	HX_VISIT_MEMBER_NAME(fileView,"fileView");
	HX_VISIT_MEMBER_NAME(pathInfo2,"pathInfo2");
	HX_VISIT_MEMBER_NAME(pathInfo,"pathInfo");
	HX_VISIT_MEMBER_NAME(view_ls2,"view_ls2");
	HX_VISIT_MEMBER_NAME(view_ls,"view_ls");
	HX_VISIT_MEMBER_NAME(sp,"sp");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Main_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"dy") ) { return dy; }
		if (HX_FIELD_EQ(inName,"dx") ) { return dx; }
		if (HX_FIELD_EQ(inName,"sp") ) { return sp; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"down") ) { return down; }
		if (HX_FIELD_EQ(inName,"view") ) { return view; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"pathI") ) { return pathI; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"repaint") ) { return repaint_dyn(); }
		if (HX_FIELD_EQ(inName,"view_ls") ) { return view_ls; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"boundary") ) { return boundary; }
		if (HX_FIELD_EQ(inName,"fileView") ) { return fileView; }
		if (HX_FIELD_EQ(inName,"pathInfo") ) { return pathInfo; }
		if (HX_FIELD_EQ(inName,"view_ls2") ) { return view_ls2; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"overCheck") ) { return overCheck_dyn(); }
		if (HX_FIELD_EQ(inName,"pathInfo2") ) { return pathInfo2; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"mouseMoved") ) { return mouseMoved_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"createViews") ) { return createViews_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"mouseClicked") ) { return mouseClicked_dyn(); }
		if (HX_FIELD_EQ(inName,"mouseDragged") ) { return mouseDragged_dyn(); }
		if (HX_FIELD_EQ(inName,"mousePressed") ) { return mousePressed_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"mouseReleased") ) { return mouseReleased_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"setupListeners") ) { return setupListeners_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Main_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"dy") ) { dy=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"dx") ) { dx=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"sp") ) { sp=inValue.Cast< ::flash::display::Sprite >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"down") ) { down=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"view") ) { view=inValue.Cast< ::finda::View_ls >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"pathI") ) { pathI=inValue.Cast< ::finda::PathInfo >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"view_ls") ) { view_ls=inValue.Cast< ::finda::View_ls >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"boundary") ) { boundary=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"fileView") ) { fileView=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"pathInfo") ) { pathInfo=inValue.Cast< ::finda::PathInfo >(); return inValue; }
		if (HX_FIELD_EQ(inName,"view_ls2") ) { view_ls2=inValue.Cast< ::finda::View_ls >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"pathInfo2") ) { pathInfo2=inValue.Cast< ::finda::PathInfo >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Main_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("boundary"));
	outFields->push(HX_CSTRING("down"));
	outFields->push(HX_CSTRING("dy"));
	outFields->push(HX_CSTRING("dx"));
	outFields->push(HX_CSTRING("pathI"));
	outFields->push(HX_CSTRING("view"));
	outFields->push(HX_CSTRING("fileView"));
	outFields->push(HX_CSTRING("pathInfo2"));
	outFields->push(HX_CSTRING("pathInfo"));
	outFields->push(HX_CSTRING("view_ls2"));
	outFields->push(HX_CSTRING("view_ls"));
	outFields->push(HX_CSTRING("sp"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("mouseReleased"),
	HX_CSTRING("mouseClicked"),
	HX_CSTRING("mouseDragged"),
	HX_CSTRING("mousePressed"),
	HX_CSTRING("overCheck"),
	HX_CSTRING("mouseMoved"),
	HX_CSTRING("repaint"),
	HX_CSTRING("setupListeners"),
	HX_CSTRING("createViews"),
	HX_CSTRING("boundary"),
	HX_CSTRING("down"),
	HX_CSTRING("dy"),
	HX_CSTRING("dx"),
	HX_CSTRING("pathI"),
	HX_CSTRING("view"),
	HX_CSTRING("fileView"),
	HX_CSTRING("pathInfo2"),
	HX_CSTRING("pathInfo"),
	HX_CSTRING("view_ls2"),
	HX_CSTRING("view_ls"),
	HX_CSTRING("sp"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Main_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Main_obj::__mClass,"__mClass");
};

Class Main_obj::__mClass;

void Main_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("finda.Main"), hx::TCanCast< Main_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Main_obj::__boot()
{
}

} // end namespace finda
