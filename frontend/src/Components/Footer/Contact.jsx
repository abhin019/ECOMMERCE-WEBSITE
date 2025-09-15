import React from 'react'
import './Contact.css'

const Contact = () => {
  return (
    <div className="contact-container">
      <h1>Contact Us</h1>
      <div className="contact-details">
        <p>If you have any questions or inquiries, please reach out to us at:</p>
        <div className="contact-email">
          <h2>Customer Support</h2>
          <a href="mailto:support@shopper.com" className="email-link">
            support@stylez.com
          </a>
        </div>
        <div className="contact-hours">
          <h3>Support Hours</h3>
          <p>Monday - Friday: 9:00 AM - 5:00 PM</p>
          <p>Saturday: 10:00 AM - 2:00 PM</p>
          <p>Sunday: Closed</p>
        </div>
      </div>
    </div>
  )
}

export default Contact