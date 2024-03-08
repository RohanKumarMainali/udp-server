import dgram from "dgram";

const socket = dgram.createSocket("udp4");
socket.bind(5000);
socket.on("message", (msg, info) => {
  console.log(`server got: ${msg} from ${info.address}:${info.port}`);
});
