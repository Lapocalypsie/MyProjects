/*
    IndexBar.js

    This component provides the section and title display that allows the user to 
    browse the available articles and select one for display. 

    props:
      setCurrentArticle - Function to call set current article displayed
      currentArticle - The article to render
  */
import React, { useState, useEffect } from "react";
import SectionsView from "./SectionsView";
import TitlesView from "./TitlesView";
import ArticleShape from "./ArticleShape";
import PropTypes from "prop-types";

export default function IndexBar({ setCurrentArticle, currentArticle }) {
  const [selectedSection, setSelectedSection] = useState(null);
  const [section, setSection] = useState([]);
  const [titles, setTitle] = useState([]);
  const [updateSection, setUpdateSection] = useState(undefined);

  function getFirstChar(stringc) {
    return stringc.charAt(0);
  }

  // eslint-disable-next-line no-shadow
  function changeSelectedSection(section) {
    setSelectedSection(section);
    setCurrentArticle(undefined);
  }

  useEffect(() => {
    if (currentArticle) {
      const compareletter = getFirstChar(currentArticle.title);
      if (compareletter !== selectedSection) {
        setSelectedSection(compareletter);
      }
    }
  }, [currentArticle, selectedSection]);

  useEffect(() => {
    fetch(`/api/sections`)
      .then((response) => response.json())
      .then((data) => {
        setSection(data);
      })
      .catch((error) => {
        console.error(error);
      });
  }, []);

  useEffect(() => {
    if (
      !selectedSection ||
      (section.length > 0 && !section.includes(selectedSection))
    ) {
      setUpdateSection(true);
    } else {
      setUpdateSection(false);
    }
  }, [selectedSection, section]);

  useEffect(() => {
    if (selectedSection || updateSection) {
      fetch(`/api/articles?section=${selectedSection}`)
        .then((response) => response.json())
        .then((data) => {
          setTitle(data);
        })
        .catch((error) => {
          console.error(error);
        });
    } else {
      setTitle([]);
    }
  }, [selectedSection, updateSection]);

  {
    return (
      <>
        <SectionsView
          sections={section}
          selectSection={changeSelectedSection}
        />
        {selectedSection ? (
          <TitlesView titles={titles} setCurrentArticle={setCurrentArticle} />
        ) : (
          <p>Please select a section</p>
        )}
      </>
    );
  }
}

IndexBar.propTypes = {
  setCurrentArticle: PropTypes.func.isRequired,
  currentArticle: ArticleShape,
};
