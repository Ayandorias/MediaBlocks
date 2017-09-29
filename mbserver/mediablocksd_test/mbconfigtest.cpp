/*
 * MediaBlocks
 *
 * Copyright (C) 2017 - 2019 Bruno Pierucki
 *
 * Author: Bruno Pierucki <bp@nebenwelten.net>
 *
 */
//// begin includes
//// end includes

//// begin MediaBlocks specific includes
#include <configuration.hpp>
#include <mediablocks.hpp>
#include <QObject>
#include <QtTest>
//// end MediaBlocks specific includes

//// begin using namespaces
//// end using namespaces

//// begin global definition
//// end global definition

//// begin forward declarations
//// end forward declarations

//// begin extern declaration
//// end extern declaration

namespace MediaBlocks {
namespace Test {
/**
 * \class _Configuration
 * \ingroup group_configuration_device
 *
 * \brief Test class for MediaBlocks::Configuration
 *
 */
	class _Configuration : public QObject
	{
		Q_OBJECT
		//// begin _Configuration public member methods
	public:
		_Configuration();
		virtual ~_Configuration();
		//// end _Configuration public member methods

		//// begin _Configuration public member methods (internal use only)
	public:
		//// end _Configuration public member methods (internal use only)

		//// begin _Configuration protected member methods
	protected:
		//// end _Configuration protected member methods

		//// begin _Configuration protected member methods (internal use only)
	protected:
		//// begin _Configuration protected member methods (internal use only)

		//// begin _Configuration private member methods
	private:
		QString getRooms();
		//// end _Configuration private member methods

	private slots:
		void factoryReset();

		void setDeviceName();
		void setDeviceNameNotAvailable();

		void setMusicDb();
		void setMusicDbNotAvailable();

		void useAsServer();
		void useAsServerNotAvailable();

		void checkEmptyRoomList();

		void createNewRoom();
		void createNewRoomExists();
		void createNewRoomNotAvailable();

		void checkAllRooms();

		void updateRoom();
		void updateRoomNotFound();
		void updateRoomNotAvailable();

		void getRoomById();
		void getRoomByIdNotFound();
		void getRoomByIdNotAvailable();

		void deleteRoomById();
		void deleteRoomByIdNotExist();
		void deleteRoomByIdNotAvailable();
		//// begin _Configuration public member
	public:
		//// end _Configuration public member

		//// begin _Configuration protected member
	protected:
		//// end _Configuration protected member

		//// begin _Configuration private member
	private:
		//// end _Configuration private member
	};
}	// namespace Test
}	// namespace MediaBlocks


/*
 * MediaBlocks
 *
 * Copyright (C) 2017 - 2019 Bruno Pierucki
 *
 * Author: Bruno Pierucki <bp@nebenwelten.net>
 */

//// begin includes
//// end includes

//// begin MediaBlocks specific includes
//// end MediaBlocks specific includes

//// begin using namespaces
//// end using namespaces

//// begin global definition
//// end global definition

//// begin extern declaration
//// end extern declaration

//// begin _Configuration static definitions
//// end _Configuration static definitions

//// begin _Configuration static functions
//// end _Configuration static functions

//// begin _Configuration public member methods
/**********************************************************************************************************************/
MediaBlocks::Test::_Configuration::_Configuration()
	:QObject() {
}
/**********************************************************************************************************************/
MediaBlocks::Test::_Configuration::~_Configuration() {
}
//// end _Configuration public member methods

//// begin _Configuration public member methods (internal use only)
//// end _Configuration public member methods (internal use only)

//// begin _Configuration protected member methods
//// end _Configuration protected member methods

//// begin _Configuration protected member methods (internal use only)
//// begin _Configuration protected member methods (internal use only)

//// begin _Configuration private member methods
QString MediaBlocks::Test::_Configuration::getRooms() {
	MediaBlocks::Configuration config(this);
	QJsonObject obj = config.getRooms();
	QJsonDocument doc(obj);
	QString compact = doc.toJson(QJsonDocument::Compact);

	return compact;
}
//// end _Configuration private member methods

//// begin _Configuration public slots
//// end _Configuration public slots

//// begin _Configuration protected slots
//// end _Configuration protected slots

//// begin _Configuration private slots
/**********************************************************************************************************************/
void MediaBlocks::Test::_Configuration::factoryReset() {
	MediaBlocks::Configuration config(this);
	QJsonDocument doc = config.setFactoryReset();
	QString compact = doc.toJson(QJsonDocument::Compact);

	qDebug() << compact;
	QVERIFY(QString(compact) == "{\"devicename\":\"MediaBlocks\","
							"\"local\":{\"enbale\":true,\"library\":\"sqlite\",\"media_dir\":\"<path-to-your-music>\"},"
							"\"m3u\":{\"enable\":true,\"playlist_dir\":\"<path-to-your-playlists>\"},"
							"\"rooms\":[],\"use_as_server\":false}");
}
/**********************************************************************************************************************/
void MediaBlocks::Test::_Configuration::setDeviceName() {
	QJsonDocument doc;
	QJsonObject device;
	MediaBlocks::Configuration config(this);

	device.insert("devicename", QJsonValue("MB-For-Living"));
	QJsonObject obj = config.setDeviceName(device);
	doc.setObject(obj);
	QString compact = doc.toJson(QJsonDocument::Compact);

	qDebug() << compact;
	QVERIFY(QString(compact) == "{\"devicename\":\"MB-For-Living\",\"music_db\":\"/mnt/sdcard/data/db/music.sqlite3\",\"rooms\":[],\"use_as_server\":false}");
}
/**********************************************************************************************************************/
void MediaBlocks::Test::_Configuration::setDeviceNameNotAvailable() {
	QJsonDocument doc;
	QJsonObject device;
	MediaBlocks::Configuration config(this);

	device.insert("device_name", QJsonValue("MB-For-Living"));
	QJsonObject obj = config.setDeviceName(device);
	doc.setObject(obj);
	QString compact = doc.toJson(QJsonDocument::Compact);

	qDebug() << compact;
	QVERIFY(QString(compact) == "{\"code\":4,\"message\":\"Request is not available!\"}");
}
/**********************************************************************************************************************/
void MediaBlocks::Test::_Configuration::setMusicDb(){
	QJsonDocument doc;
	QJsonObject device;
	MediaBlocks::Configuration config(this);

	device.insert("music_db", QJsonValue("/home/heresy/Musik/music.sqlite3"));
	QJsonObject obj = config.setMusicDb(device);
	doc.setObject(obj);
	QString compact = doc.toJson(QJsonDocument::Compact);

	qDebug() << compact;
	QVERIFY(QString(compact) == "{\"devicename\":\"MB-For-Living\",\"music_db\":\"/home/heresy/Musik/music.sqlite3\",\"rooms\":[],\"use_as_server\":false}");
}
/**********************************************************************************************************************/
void MediaBlocks::Test::_Configuration::setMusicDbNotAvailable(){
	QJsonDocument doc;
	QJsonObject device;
	MediaBlocks::Configuration config(this);

	device.insert("musicdb", QJsonValue("/home/user/Music/music.sqlite3"));
	QJsonObject obj = config.setDeviceName(device);
	doc.setObject(obj);
	QString compact = doc.toJson(QJsonDocument::Compact);

	qDebug() << compact;
	QVERIFY(QString(compact) == "{\"code\":4,\"message\":\"Request is not available!\"}");
}
/**********************************************************************************************************************/
void MediaBlocks::Test::_Configuration::useAsServer(){
	QJsonDocument doc;
	QJsonObject device;
	MediaBlocks::Configuration config(this);

	device.insert("use_as_server", QJsonValue(true));
	QJsonObject obj = config.useAsServer(device);
	doc.setObject(obj);
	QString compact = doc.toJson(QJsonDocument::Compact);

	qDebug() << compact;
	QVERIFY(QString(compact) == "{\"devicename\":\"MB-For-Living\",\"music_db\":\"/home/heresy/Musik/music.sqlite3\",\"rooms\":[],\"use_as_server\":true}");
}
/**********************************************************************************************************************/
void MediaBlocks::Test::_Configuration::useAsServerNotAvailable(){
	QJsonDocument doc;
	QJsonObject device;
	MediaBlocks::Configuration config(this);

	device.insert("useasserver", QJsonValue(true));
	QJsonObject obj = config.setDeviceName(device);
	doc.setObject(obj);
	QString compact = doc.toJson(QJsonDocument::Compact);

	qDebug() << compact;
	QVERIFY(QString(compact) == "{\"code\":4,\"message\":\"Request is not available!\"}");
}
/**********************************************************************************************************************/
void MediaBlocks::Test::_Configuration::checkEmptyRoomList() {
	QString compact = getRooms();
	QVERIFY(QString(compact) == "{\"rooms\":[]}");
}
/**********************************************************************************************************************/
void MediaBlocks::Test::_Configuration::createNewRoom() {
	MediaBlocks::Configuration config(this);
	QJsonObject room;
	room.insert("roomname", QJsonValue("Office"));

	QJsonObject newRoom = config.createRoom(room);
	QJsonDocument doc(newRoom);
	QString compact = doc.toJson(QJsonDocument::Compact);

	qDebug() << compact;
	QVERIFY(QString(compact) == "{\"id\":0,\"name\":\"Office\",\"port\":6001}");

	room.remove("roomname");
	room.insert("roomname", QJsonValue("Living Room"));
	newRoom = config.createRoom(room);
	doc.setObject(newRoom);
	compact = doc.toJson(QJsonDocument::Compact);

	qDebug() << compact;
	QVERIFY(QString(compact) == "{\"id\":1,\"name\":\"Living Room\",\"port\":6002}");

}
/**********************************************************************************************************************/
void MediaBlocks::Test::_Configuration::createNewRoomExists() {
	MediaBlocks::Configuration config(this);
	QJsonDocument doc;
	QJsonObject room;

	room.insert("roomname", QJsonValue("Office"));
	QJsonObject newRoom = config.createRoom(room);
	doc.setObject(newRoom);
	QString compact = doc.toJson(QJsonDocument::Compact);

	qDebug() << compact;
	QVERIFY(QString(compact) == "{\"code\":1,\"message\":\"Resource available!\"}");
}
/**********************************************************************************************************************/
void MediaBlocks::Test::_Configuration::createNewRoomNotAvailable() {
	MediaBlocks::Configuration config(this);
	QJsonDocument doc;
	QJsonObject room;

	room.insert("room_name", QJsonValue("Office"));
	QJsonObject newRoom = config.createRoom(room);
	doc.setObject(newRoom);
	QString compact = doc.toJson(QJsonDocument::Compact);

	qDebug() << compact;
	QVERIFY(QString(compact) == "{\"code\":4,\"message\":\"Request is not available!\"}");
}
/**********************************************************************************************************************/
/**
 * @brief MediaBlocks::Test::_Configuration::checkAllRooms
 *
 * @test This is a test for test entry.
 */
void MediaBlocks::Test::_Configuration::checkAllRooms() {
	QString compact = getRooms();
	QVERIFY(QString(compact) == "{\"rooms\":[{\"id\":0,\"name\":\"Office\",\"port\":6001},{\"id\":1,\"name\":\"Living Room\",\"port\":6002}]}");
}
/**********************************************************************************************************************/
void MediaBlocks::Test::_Configuration::updateRoom() {
	qDebug() << "Change Name von Room with ID = 0 to Bedroom.";
	MediaBlocks::Configuration config(this);
	QJsonDocument doc = QJsonDocument::fromJson("{\"id\":0,\"name\":\"Bedroom\"}");
	QJsonObject room = doc.object();

	QJsonObject newRoom = config.updateRoom(room);
	doc.setObject(newRoom);
	QString compact = doc.toJson(QJsonDocument::Compact);
	qDebug() << compact;
	QVERIFY(QString(compact) == "{\"id\":0,\"name\":\"Bedroom\",\"port\":6001}");
}
/**********************************************************************************************************************/
void MediaBlocks::Test::_Configuration::updateRoomNotFound() {
	QString compact;

	MediaBlocks::Configuration config(this);
	QJsonDocument doc = QJsonDocument::fromJson("{\"id\":12,\"name\":\"Bedroom\"}");
	QJsonObject room = doc.object();

	QJsonObject noRoom = config.updateRoom(room);
	doc.setObject(noRoom);
	compact = doc.toJson(QJsonDocument::Compact);
	qDebug() << compact;
	QVERIFY(QString(compact) == "{\"code\":2,\"message\":\"Resource not found!\"}");
}
/**********************************************************************************************************************/
void MediaBlocks::Test::_Configuration::updateRoomNotAvailable() {
	QString compact;

	MediaBlocks::Configuration config(this);
	QJsonDocument doc = QJsonDocument::fromJson("{\"id_not_found\":12,\"name\":\"Bedroom\"}");
	QJsonObject room = doc.object();

	QJsonObject noRoom = config.updateRoom(room);
	doc.setObject(noRoom);
	compact = doc.toJson(QJsonDocument::Compact);
	qDebug() << compact;
	QVERIFY(QString(compact) == "{\"code\":4,\"message\":\"Request is not available!\"}");
}
/**********************************************************************************************************************/
void MediaBlocks::Test::_Configuration::getRoomById() {
	MediaBlocks::Configuration config(this);
	QJsonObject id;
	id.insert("id", QJsonValue(0));

	QJsonObject room = config.getRoomById(id);
	QJsonDocument doc(room);
	QString compact = doc.toJson(QJsonDocument::Compact);
	qDebug() << compact;
	QVERIFY(QString(compact) == "{\"id\":0,\"name\":\"Bedroom\",\"port\":6001}");
}
/**********************************************************************************************************************/
void MediaBlocks::Test::_Configuration::getRoomByIdNotFound() {
	MediaBlocks::Configuration config(this);
	QString compact;
	QJsonObject id;

	id.insert("id", QJsonValue(100));
	QJsonObject room = config.getRoomById(id);
	QJsonDocument doc(room);
	compact = doc.toJson(QJsonDocument::Compact);

	qDebug() << compact;
	QVERIFY(QString(compact) == "{\"code\":2,\"message\":\"Resource not found!\"}");
}
/**********************************************************************************************************************/
void MediaBlocks::Test::_Configuration::getRoomByIdNotAvailable() {
	MediaBlocks::Configuration config(this);
	QString compact;
	QJsonObject id;

	id.insert("id_test", QJsonValue(0));
	QJsonObject room = config.getRoomById(id);
	QJsonDocument doc(room);
	compact = doc.toJson(QJsonDocument::Compact);

	qDebug() << compact;
	QVERIFY(QString(compact) == "{\"code\":4,\"message\":\"Request is not available!\"}");
}
/**********************************************************************************************************************/
void MediaBlocks::Test::_Configuration::deleteRoomById() {
	MediaBlocks::Configuration config(this);
	QJsonObject del;
	QString compact;

	del.insert("id", QJsonValue(1));

	QJsonObject deleted = config.deleteRoomById(del);
	QJsonDocument doc(deleted);
	compact = doc.toJson(QJsonDocument::Compact);

	qDebug() << compact;
	QVERIFY(QString(compact) == "{\"code\":65535,\"message\":\"Request processed successfully\"}");
}
/**********************************************************************************************************************/
void MediaBlocks::Test::_Configuration::deleteRoomByIdNotExist() {
	MediaBlocks::Configuration config(this);
	QJsonObject del;
	QString compact;

	del.insert("id", QJsonValue(100));

	QJsonObject deleted = config.deleteRoomById(del);
	QJsonDocument doc(deleted);
	compact = doc.toJson(QJsonDocument::Compact);

	qDebug() << compact;
	QVERIFY(QString(compact) == "{\"code\":2,\"message\":\"Resource not found!\"}");
}
/**********************************************************************************************************************/
void MediaBlocks::Test::_Configuration::deleteRoomByIdNotAvailable() {
	MediaBlocks::Configuration config(this);
	QJsonObject del;
	QString compact;

	del.insert("room_id", QJsonValue(0));

	QJsonObject deleted = config.deleteRoomById(del);
	QJsonDocument doc(deleted);
	compact = doc.toJson(QJsonDocument::Compact);

	qDebug() << compact;
	QVERIFY(QString(compact) == "{\"code\":4,\"message\":\"Request is not available!\"}");
}
//// end _Configuration private slots


QTEST_APPLESS_MAIN(MediaBlocks::Test::_Configuration)

#include "mbconfigtest.moc"
