import "../styles/globals.css";
import Head from "next/head";
import styles from "../styles/Simplepedia.module.css";
import { useRouter } from "next/router";
import PropTypes from "prop-types";
import React, { useState, useEffect } from "react";

function MainApp({ Component, pageProps }) {
  const [currentArticle, setCurrentArticle] = useState(undefined);
  const router = useRouter();
  const { id } = router.query;

  useEffect(() => {
    if (id === undefined) {
      setCurrentArticle(undefined);
    } else if (
      currentArticle === undefined ||
      Number(id) !== currentArticle.id
    ) {
      fetch(`/api/articles/${id}`)
        .then((response) => response.json())
        .then((data) => {
          setCurrentArticle(data);
        })
        .catch((error) => {
          console.error(error);
        });
    }
  }, [id, currentArticle]);

  function selectCurrentArticle(article) {
    if (article === undefined) {
      router.push("/articles");
    } else {
      setCurrentArticle(article);
      router.push(`/articles/${article.id}`);
    }
  }
  const props = {
    ...pageProps,
    currentArticle,
    setCurrentArticle: selectCurrentArticle,
  };

  return (
    <div className={styles.container}>
      <Head>
        <title>Simplepedia</title>
        <link rel="icon" href="/favicon.ico" />
      </Head>
      <main>
        <h1 className="title">Simplepedia</h1>
        <Component {...props} />
      </main>

      <footer>CS 312 Assignment 4</footer>
    </div>
  );
}

export default MainApp;

MainApp.propTypes = {
  Component: PropTypes.elementType.isRequired,
  pageProps: PropTypes.shape({}),
};
