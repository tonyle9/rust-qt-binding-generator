/* generated by rust_qt_binding_generator */
#include "test_objects_rust.h"

namespace {

    typedef void (*qstring_set)(QString* val, const char* utf8, int nbytes);
    void set_qstring(QString* val, const char* utf8, int nbytes) {
        *val = QString::fromUtf8(utf8, nbytes);
    }
    inline void innerObjectDescriptionChanged(InnerObject* o)
    {
        emit o->descriptionChanged();
    }
}
extern "C" {
    Group::Private* group_new(Group*, Person*, InnerObject*, void (*)(InnerObject*));
    void group_free(Group::Private*);
    Person::Private* group_person_get(const Group::Private*);
};

extern "C" {
    InnerObject::Private* inner_object_new(InnerObject*, void (*)(InnerObject*));
    void inner_object_free(InnerObject::Private*);
    void inner_object_description_get(const InnerObject::Private*, QString*, qstring_set);
    void inner_object_description_set(InnerObject::Private*, const ushort *str, int len);
};

extern "C" {
    Person::Private* person_new(Person*, InnerObject*, void (*)(InnerObject*));
    void person_free(Person::Private*);
    InnerObject::Private* person_object_get(const Person::Private*);
};

Group::Group(bool /*owned*/, QObject *parent):
    QObject(parent),
    m_person(new Person(false, this)),
    m_d(0),
    m_ownsPrivate(false)
{
}

Group::Group(QObject *parent):
    QObject(parent),
    m_person(new Person(false, this)),
    m_d(group_new(this, m_person, m_person->m_object,
        innerObjectDescriptionChanged)),
    m_ownsPrivate(true)
{
    m_person->m_d = group_person_get(m_d);
    m_person->m_object->m_d = person_object_get(m_person->m_d);
}

Group::~Group() {
    if (m_ownsPrivate) {
        group_free(m_d);
    }
}
const Person* Group::person() const
{
    return m_person;
}
Person* Group::person()
{
    return m_person;
}
InnerObject::InnerObject(bool /*owned*/, QObject *parent):
    QObject(parent),
    m_d(0),
    m_ownsPrivate(false)
{
}

InnerObject::InnerObject(QObject *parent):
    QObject(parent),
    m_d(inner_object_new(this,
        innerObjectDescriptionChanged)),
    m_ownsPrivate(true)
{
}

InnerObject::~InnerObject() {
    if (m_ownsPrivate) {
        inner_object_free(m_d);
    }
}
QString InnerObject::description() const
{
    QString v;
    inner_object_description_get(m_d, &v, set_qstring);
    return v;
}
void InnerObject::setDescription(const QString& v) {
    inner_object_description_set(m_d, reinterpret_cast<const ushort*>(v.data()), v.size());
}
Person::Person(bool /*owned*/, QObject *parent):
    QObject(parent),
    m_object(new InnerObject(false, this)),
    m_d(0),
    m_ownsPrivate(false)
{
}

Person::Person(QObject *parent):
    QObject(parent),
    m_object(new InnerObject(false, this)),
    m_d(person_new(this, m_object,
        innerObjectDescriptionChanged)),
    m_ownsPrivate(true)
{
    m_object->m_d = person_object_get(m_d);
}

Person::~Person() {
    if (m_ownsPrivate) {
        person_free(m_d);
    }
}
const InnerObject* Person::object() const
{
    return m_object;
}
InnerObject* Person::object()
{
    return m_object;
}
