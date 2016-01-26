#ifndef FLATHEADERS
#include "simple_message/messages/io_read_request_message.h"
#include "simple_message/joint_data.h"
#include "simple_message/byte_array.h"
#include "simple_message/log_wrapper.h"
#else
#include "io_read_request_message.h"
#include "joint_data.h"
#include "byte_array.h"
#include "log_wrapper.h"
#endif

using namespace industrial::shared_types;
using namespace industrial::byte_array;
using namespace industrial::simple_message;
using namespace industrial::joint_data;

namespace industrial
{
namespace io_read_request_message
{

IOReadRequestMessage::IOReadRequestMessage(void)
{
  this->init();
}

IOReadRequestMessage::~IOReadRequestMessage(void)
{

}

bool IOReadRequestMessage::init(industrial::simple_message::SimpleMessage & msg)
{
  ByteArray data = msg.getData();

  this->init();
  return this->unload(&data);
}

void IOReadRequestMessage::init()
{
  this->setMessageType(msg_type);
  this->message_id = 0;
}

bool IOReadRequestMessage::load(ByteArray *buffer)
{
  bool rtn = true;
  LOG_COMM("Executing io io read request message load");
  rtn &= buffer->load(message_id);
  if (!rtn) return rtn;
  
  rtn &= buffer->load((industrial::shared_types::shared_int)items.size());
  if (!rtn) return rtn;
  
  for (int i = 0; i < items.size(); ++i)
  {
    rtn &= buffer->load(items[i].type);
    if (!rtn) return rtn;
    rtn &= buffer->load(items[i].index);
    if (!rtn) return rtn;
  }
  
  return rtn;
}

bool IOReadRequestMessage::unload(ByteArray *buffer)
{
  throw std::runtime_error("Not implemented");
}

}
}
