#include <string>
#include <iostream>

#include "caf/all.hpp"

using std::endl;
using std::string;

using namespace caf;

behavior pong(event_based_actor* self, string selfname) {
  // return the (initial) actor behavior
  return {
    // a handler for messages containing a single string
    // that replies with a string
    [=](const string& what) -> string {
      // prints received message
      aout(self) << selfname << ": " << what << endl;
      // reply Pong
      return string("Pong...");
    }
  };
}

void ping(event_based_actor* self, const actor& buddy, string selfname) {
  // send Ping to our buddy ...
  self->request(buddy, std::chrono::seconds(10), "Ping...").then(
    // ... wait up to 10s for a response ...
    [=](const string& what) {
      // ... and print it
      aout(self) << selfname << ": " << what << endl;
	  //if reply is as expected, restart ping again
	  if(what.compare("Pong...") == 0) {
		  ping(self, buddy, selfname);
	  }
    }
  );
}

int main() {
  // our CAF environment
  actor_system_config cfg;
  actor_system system{cfg};
  // create a new actor that calls 'pong()'
  auto actor_B = system.spawn(pong, "B");
  // create another actor that calls 'ping(actor_B)';
  auto actor_A = system.spawn(ping, actor_B, "A");
  // system will wait until both actors are destroyed before leaving main
}