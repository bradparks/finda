#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_finda_MainOpenfl
#include <finda/MainOpenfl.h>
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

Void MainOpenfl_obj::__construct()
{
HX_STACK_PUSH("MainOpenfl::new","finda/MainOpenfl.hx",8);
{
	HX_STACK_LINE(21)
	this->boundary = (int)250;
	HX_STACK_LINE(20)
	this->down = false;
	HX_STACK_LINE(25)
	super::__construct();
	HX_STACK_LINE(27)
	this->sp = ::flash::display::Sprite_obj::__new();
	HX_STACK_LINE(28)
	this->addChild(this->sp);
	HX_STACK_LINE(30)
	::String offsetDir = HX_CSTRING("../../../../../../");		HX_STACK_VAR(offsetDir,"offsetDir");
	HX_STACK_LINE(31)
	this->pathInfo = ::finda::PathInfo_obj::__new((offsetDir + HX_CSTRING("./")));
	HX_STACK_LINE(32)
	this->pathInfo2 = ::finda::PathInfo_obj::__new((offsetDir + HX_CSTRING("../")));
	HX_STACK_LINE(34)
	this->view_ls = ::finda::View_ls_obj::__new(this->pathInfo,(int)25,(int)25);
	HX_STACK_LINE(35)
	this->view_ls2 = ::finda::View_ls_obj::__new(this->pathInfo2,(int)300,(int)25);
	HX_STACK_LINE(37)
	this->repaint();
	HX_STACK_LINE(38)
	this->setupListeners();
}
;
	return null();
}

MainOpenfl_obj::~MainOpenfl_obj() { }

Dynamic MainOpenfl_obj::__CreateEmpty() { return  new MainOpenfl_obj; }
hx::ObjectPtr< MainOpenfl_obj > MainOpenfl_obj::__new()
{  hx::ObjectPtr< MainOpenfl_obj > result = new MainOpenfl_obj();
	result->__construct();
	return result;}

Dynamic MainOpenfl_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MainOpenfl_obj > result = new MainOpenfl_obj();
	result->__construct();
	return result;}

Void MainOpenfl_obj::mouseReleased( ::flash::events::MouseEvent e){
{
		HX_STACK_PUSH("MainOpenfl::mouseReleased","finda/MainOpenfl.hx",118);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(119)
		this->down = false;
		HX_STACK_LINE(122)
		if (((bool((this->fileView->__Field(HX_CSTRING("x"),true) < this->boundary)) && bool((this->view == this->view_ls2))))){
			HX_STACK_LINE(123)
			::sys::FileSystem_obj::rename(((this->pathI->path + HX_CSTRING("/")) + this->fileView->__Field(HX_CSTRING("file"),true)->__Field(HX_CSTRING("name"),true)),((this->pathInfo->path + HX_CSTRING("/")) + this->fileView->__Field(HX_CSTRING("file"),true)->__Field(HX_CSTRING("name"),true)));
			HX_STACK_LINE(125)
			this->pathI->changePath(this->pathInfo->path);
			HX_STACK_LINE(126)
			this->pathI->changePath(this->pathInfo2->path);
			HX_STACK_LINE(127)
			this->view_ls->change();
			HX_STACK_LINE(128)
			this->view_ls2->change();
			HX_STACK_LINE(129)
			this->repaint();
		}
		else{
			HX_STACK_LINE(131)
			if (((bool((this->fileView->__Field(HX_CSTRING("x"),true) > this->boundary)) && bool((this->view == this->view_ls))))){
				HX_STACK_LINE(132)
				::sys::FileSystem_obj::rename(((this->pathI->path + HX_CSTRING("/")) + this->fileView->__Field(HX_CSTRING("file"),true)->__Field(HX_CSTRING("name"),true)),((this->pathInfo2->path + HX_CSTRING("/")) + this->fileView->__Field(HX_CSTRING("file"),true)->__Field(HX_CSTRING("name"),true)));
				HX_STACK_LINE(134)
				this->pathI->changePath(this->pathInfo->path);
				HX_STACK_LINE(135)
				this->pathI->changePath(this->pathInfo2->path);
				HX_STACK_LINE(136)
				this->view_ls->change();
				HX_STACK_LINE(137)
				this->view_ls2->change();
				HX_STACK_LINE(138)
				this->repaint();
			}
			else{
				HX_STACK_LINE(141)
				this->view_ls->change();
				HX_STACK_LINE(142)
				this->view_ls2->change();
				HX_STACK_LINE(143)
				this->repaint();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MainOpenfl_obj,mouseReleased,(void))

Void MainOpenfl_obj::mouseClicked( ::flash::events::MouseEvent e){
{
		HX_STACK_PUSH("MainOpenfl::mouseClicked","finda/MainOpenfl.hx",112);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(112)
		if (((this->fileView != null()))){
			HX_STACK_LINE(114)
			this->view->clicked(this->fileView);
			HX_STACK_LINE(115)
			this->repaint();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MainOpenfl_obj,mouseClicked,(void))

Void MainOpenfl_obj::mouseDragged( ::flash::events::MouseEvent e){
{
		HX_STACK_PUSH("MainOpenfl::mouseDragged","finda/MainOpenfl.hx",103);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(105)
		this->fileView->__FieldRef(HX_CSTRING("x")) = ::Std_obj::_int((e->localX - this->dx));
		HX_STACK_LINE(106)
		this->fileView->__FieldRef(HX_CSTRING("y")) = ::Std_obj::_int((e->localY - this->dy));
		HX_STACK_LINE(107)
		this->fileView->__FieldRef(HX_CSTRING("change")) = true;
		HX_STACK_LINE(109)
		this->repaint();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MainOpenfl_obj,mouseDragged,(void))

Void MainOpenfl_obj::mousePressed( ::flash::events::MouseEvent e){
{
		HX_STACK_PUSH("MainOpenfl::mousePressed","finda/MainOpenfl.hx",87);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		struct _Function_1_1{
			inline static Dynamic Block( ::flash::events::MouseEvent &e){
				HX_STACK_PUSH("*::closure","finda/MainOpenfl.hx",91);
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("x") , e->localX,false);
					__result->Add(HX_CSTRING("y") , e->localY,false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(91)
		Dynamic point = _Function_1_1::Block(e);		HX_STACK_VAR(point,"point");
		HX_STACK_LINE(93)
		if (((this->fileView != null()))){
			HX_STACK_LINE(95)
			this->dx = ::Std_obj::_int((point->__Field(HX_CSTRING("x"),true) - this->fileView->__Field(HX_CSTRING("x"),true)));
			HX_STACK_LINE(96)
			this->dy = ::Std_obj::_int((point->__Field(HX_CSTRING("y"),true) - this->fileView->__Field(HX_CSTRING("y"),true)));
			HX_STACK_LINE(97)
			this->down = true;
		}
		else{
			HX_STACK_LINE(98)
			this->down = false;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MainOpenfl_obj,mousePressed,(void))

Void MainOpenfl_obj::overCheck( ::flash::events::MouseEvent e){
{
		HX_STACK_PUSH("MainOpenfl::overCheck","finda/MainOpenfl.hx",61);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(62)
		Dynamic fileView1 = this->view_ls->overCheck(e);		HX_STACK_VAR(fileView1,"fileView1");
		HX_STACK_LINE(63)
		Dynamic fileView2 = this->view_ls2->overCheck(e);		HX_STACK_VAR(fileView2,"fileView2");
		HX_STACK_LINE(64)
		bool bool1 = (fileView1 != null());		HX_STACK_VAR(bool1,"bool1");
		HX_STACK_LINE(65)
		bool bool2 = (fileView2 != null());		HX_STACK_VAR(bool2,"bool2");
		HX_STACK_LINE(66)
		if (((bool(bool1) || bool(bool2)))){
			HX_STACK_LINE(67)
			this->sp->useHandCursor = true;
			HX_STACK_LINE(68)
			if ((bool1)){
				HX_STACK_LINE(69)
				this->fileView = fileView1;
				HX_STACK_LINE(70)
				this->pathI = this->pathInfo;
				HX_STACK_LINE(71)
				this->view = this->view_ls;
			}
			else{
				HX_STACK_LINE(72)
				if ((bool2)){
					HX_STACK_LINE(73)
					this->fileView = fileView2;
					HX_STACK_LINE(74)
					this->pathI = this->pathInfo2;
					HX_STACK_LINE(75)
					this->view = this->view_ls2;
				}
			}
		}
		else{
			HX_STACK_LINE(78)
			this->sp->useHandCursor = false;
			HX_STACK_LINE(79)
			this->fileView = null();
		}
		HX_STACK_LINE(81)
		if ((this->down)){
			HX_STACK_LINE(82)
			this->mouseDragged(e);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MainOpenfl_obj,overCheck,(void))

Void MainOpenfl_obj::mouseMoved( ::flash::events::MouseEvent e){
{
		HX_STACK_PUSH("MainOpenfl::mouseMoved","finda/MainOpenfl.hx",60);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(60)
		this->overCheck(e);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MainOpenfl_obj,mouseMoved,(void))

Void MainOpenfl_obj::repaint( ){
{
		HX_STACK_PUSH("MainOpenfl::repaint","finda/MainOpenfl.hx",54);
		HX_STACK_THIS(this);
		HX_STACK_LINE(55)
		while(((this->sp->get_numChildren() > (int)0))){
			HX_STACK_LINE(55)
			this->sp->removeChildAt((int)0);
		}
		HX_STACK_LINE(56)
		this->view_ls->repaint(this->sp);
		HX_STACK_LINE(57)
		this->view_ls2->repaint(this->sp);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MainOpenfl_obj,repaint,(void))

Void MainOpenfl_obj::setupListeners( ){
{
		HX_STACK_PUSH("MainOpenfl::setupListeners","finda/MainOpenfl.hx",43);
		HX_STACK_THIS(this);
		HX_STACK_LINE(44)
		this->sp->buttonMode = true;
		HX_STACK_LINE(45)
		this->sp->set_mouseChildren(false);
		HX_STACK_LINE(46)
		this->sp->useHandCursor = true;
		HX_STACK_LINE(47)
		this->sp->addEventListener(::flash::events::MouseEvent_obj::MOUSE_MOVE,this->mouseMoved_dyn(),null(),null(),null());
		HX_STACK_LINE(48)
		this->sp->addEventListener(::flash::events::MouseEvent_obj::MOUSE_DOWN,this->mousePressed_dyn(),null(),null(),null());
		HX_STACK_LINE(49)
		this->sp->addEventListener(::flash::events::MouseEvent_obj::MOUSE_UP,this->mouseReleased_dyn(),null(),null(),null());
		HX_STACK_LINE(50)
		this->sp->addEventListener(::flash::events::MouseEvent_obj::CLICK,this->mouseClicked_dyn(),null(),null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MainOpenfl_obj,setupListeners,(void))


MainOpenfl_obj::MainOpenfl_obj()
{
}

void MainOpenfl_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(MainOpenfl);
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

void MainOpenfl_obj::__Visit(HX_VISIT_PARAMS)
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

Dynamic MainOpenfl_obj::__Field(const ::String &inName,bool inCallProp)
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

Dynamic MainOpenfl_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
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

void MainOpenfl_obj::__GetFields(Array< ::String> &outFields)
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
	HX_MARK_MEMBER_NAME(MainOpenfl_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(MainOpenfl_obj::__mClass,"__mClass");
};

Class MainOpenfl_obj::__mClass;

void MainOpenfl_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("finda.MainOpenfl"), hx::TCanCast< MainOpenfl_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void MainOpenfl_obj::__boot()
{
}

} // end namespace finda
