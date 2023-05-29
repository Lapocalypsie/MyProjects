/*
  SectionsView.js

  This module displays the sections and reports when a user clicks on one.

  props:
    sections - an array of section names
    selectSection - a callback that expects a section as an argument

*/
import styles from "../styles/SectionsView.module.css";
import PropTypes from "prop-types";
//import ArticleShape from "./ArticleShape";

export default function SectionsView({ sections, selectSection }) {
  const copySections = [...sections].sort();

  const reportSelected = (section) => {
    selectSection(section);
  };

  return (
    <div className={styles.sectionList}>
      <ul>
        {copySections.map((section) => (
          <li
            key={section}
            data-testid="section"
            onClick={() => reportSelected(section)}
          >
            {section}
          </li>
        ))}
      </ul>
    </div>
  );
}

SectionsView.propTypes = {
  sections: PropTypes.arrayOf(Object).isRequired,
  selectSection: PropTypes.func.isRequired,
};
