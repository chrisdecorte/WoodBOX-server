/*
 * WoodBOX-server
 *
 * Server appliction for the DPTechnics WoodBOX.
 *
 * File: client.h
 * Description: all low level reading and writing occurs here.
 *
 * Created by: Daan Pape
 * Created on: May 10, 2014
 */

#ifndef CLIENT_H_
#define CLIENT_H_

/**
 * Write a http header to a client
 * @cl the client to write the header to
 * @code the http status code t o write
 * @summary the http status code info, for example if code = 200, summary = "Ok"
 */
void write_http_header(struct client *cl, int code, const char *summary);

/**
 * Signal a request is done and set the connection to wait
 * for another request from the client.
 * @cl the client from which the request is done
 */
void request_done(struct client *cl);

/**
 * Send an error message to the browser
 * @cl the client to send the error message to
 * @code the error code to write to the client
 * @summary the code description, for example code = 500, summary = "Internal Server Error"
 * @fmt optional error information
 */
void __printf(4, 5) send_client_error(struct client *cl, int code, const char *summary, const char *fmt, ...);

#endif /* CLIENT_H_ */
