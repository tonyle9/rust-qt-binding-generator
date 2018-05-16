/* generated by rust_qt_binding_generator */
#![allow(unknown_lints)]
#![allow(mutex_atomic, needless_pass_by_value)]
use libc::{c_char, c_ushort, c_int};
use std::slice;
use std::char::decode_utf16;

use std::sync::{Arc, Mutex};
use std::ptr::null;

use implementation::*;


pub enum QString {}

fn set_string_from_utf16(s: &mut String, str: *const c_ushort, len: c_int) {
    let utf16 = unsafe { slice::from_raw_parts(str, len as usize) };
    let characters = decode_utf16(utf16.iter().cloned())
        .into_iter()
        .map(|r| r.unwrap());
    s.clear();
    s.extend(characters);
}


pub struct PersonQObject {}

#[derive(Clone)]
pub struct PersonEmitter {
    qobject: Arc<Mutex<*const PersonQObject>>,
    user_name_changed: fn(*const PersonQObject),
}

unsafe impl Send for PersonEmitter {}

impl PersonEmitter {
    fn clear(&self) {
        *self.qobject.lock().unwrap() = null();
    }
    pub fn user_name_changed(&self) {
        let ptr = *self.qobject.lock().unwrap();
        if !ptr.is_null() {
            (self.user_name_changed)(ptr);
        }
    }
}

pub trait PersonTrait {
    fn new(emit: PersonEmitter) -> Self;
    fn emit(&self) -> &PersonEmitter;
    fn user_name(&self) -> &str;
    fn set_user_name(&mut self, value: String);
}

#[no_mangle]
pub extern "C" fn person_new(
    person: *mut PersonQObject,
    user_name_changed: fn(*const PersonQObject),
) -> *mut Person {
    let person_emit = PersonEmitter {
        qobject: Arc::new(Mutex::new(person)),
        user_name_changed: user_name_changed,
    };
    let d_person = Person::new(person_emit);
    Box::into_raw(Box::new(d_person))
}

#[no_mangle]
pub unsafe extern "C" fn person_free(ptr: *mut Person) {
    Box::from_raw(ptr).emit().clear();
}

#[no_mangle]
pub extern "C" fn person_user_name_get(
    ptr: *const Person,
    p: *mut QString,
    set: fn(*mut QString, *const c_char, c_int),
) {
    let o = unsafe { &*ptr };
    let v = o.user_name();
    let s: *const c_char = v.as_ptr() as (*const c_char);
    set(p, s, v.len() as c_int);
}

#[no_mangle]
pub extern "C" fn person_user_name_set(ptr: *mut Person, v: *const c_ushort, len: c_int) {
    let o = unsafe { &mut *ptr };
    let mut s = String::new();
    set_string_from_utf16(&mut s, v, len);
    o.set_user_name(s);
}
